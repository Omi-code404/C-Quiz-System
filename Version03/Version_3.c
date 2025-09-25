#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Question {
    char question[200];
    char options[4][100];
    char correctOption;
};

// Load questions from file
int loadQuestionsFromFile(struct Question quiz[], char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("%s file not found!\n", filename);
        return 0;
    }
    int count = 0;
    while (count < 100 && fgets(quiz[count].question, sizeof(quiz[count].question), file)) {
        quiz[count].question[strcspn(quiz[count].question, "\n")] = '\0';
        for (int i = 0; i < 4; i++) {
            if (!fgets(quiz[count].options[i], sizeof(quiz[count].options[i]), file)) {
                fclose(file);
                return count; // Return questions loaded so far if file ends unexpectedly
            }
            quiz[count].options[i][strcspn(quiz[count].options[i], "\n")] = '\0';
        }
        char answerLine[10];
        if (!fgets(answerLine, sizeof(answerLine), file)) {
            fclose(file);
            return count; // Return questions loaded so far
        }
        quiz[count].correctOption = answerLine[0];
        // skip empty line
        fgets(answerLine, sizeof(answerLine), file);
        count++;
    }
    fclose(file);
    return count;
}

// Shuffle question indexes
void shuffle(int *arr, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    struct Question quiz[100];
    char answer;
    int score = 0;
    int prevBest = 0;
    int difficulty;
    char filename[20];
    char levelName[10];

    srand(time(NULL));

    // Difficulty selection
    printf("=== MCQ Quiz Game (Version 3: Random Questions) ===\n");
    printf("Choose difficulty level:\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    printf("Enter your choice (1-3): ");

    if (scanf("%d", &difficulty) != 1 || difficulty < 1 || difficulty > 3) {
        printf("Invalid choice! Defaulting to Easy level.\n");
        difficulty = 1;
    }

    // Set filename and level name based on choice
    switch(difficulty) {
        case 1:
            strcpy(filename, "C:\\Users\\Hp\\OneDrive\\Desktop\\QuizProject\\QuizProjectV3\\EasyQUESTIONs.txt");
            strcpy(levelName, "Easy");
            break;
        case 2:
            strcpy(filename, "C:\\Users\\Hp\\OneDrive\\Desktop\\QuizProject\\QuizProjectV3\\Medium.txt");
            strcpy(levelName, "Medium");
            break;
        case 3:
            strcpy(filename, "C:\\Users\\Hp\\OneDrive\\Desktop\\QuizProject\\QuizProjectV3\\Hard.txt");
            strcpy(levelName, "Hard");
            break;
    }

    // Load questions
    int totalQuestions = loadQuestionsFromFile(quiz, filename);
    if (totalQuestions == 0) {
        return 1;
    }

    // Read history.txt (previous best score)
    FILE *hFile = fopen("C:\\Users\\Hp\\OneDrive\\Desktop\\QuizProject\\QuizProjectV3\\history.txt", "r");
    if (hFile) {
        if (fscanf(hFile, "%d", &prevBest) != 1) {
            prevBest = 0; // Set to 0 if reading fails
        }
        fclose(hFile);
    }

    printf("\nExam Level: %s\n", levelName);
    printf("Total Questions: 10\n\n");

    // Limit quiz to 10 questions maximum
    int quizQuestions = (totalQuestions < 10) ? totalQuestions : 10;

    // Create index array for shuffle
    int indexes[100];
    for (int i = 0; i < totalQuestions; i++) {
        indexes[i] = i;
    }
    shuffle(indexes, totalQuestions);

    // Show questions in random order (only 10)
    for (int k = 0; k < quizQuestions; k++) {
        int i = indexes[k];
        printf("%d: %s\n", k + 1, quiz[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", quiz[i].options[j]);
        }
        printf("Your Answer (A/B/C/D): ");
        if (scanf(" %c", &answer) != 1) {
            printf("Invalid input! Skipping question.\n\n");
            continue;
        }
        if (answer == quiz[i].correctOption || answer == quiz[i].correctOption + 32) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf(" Wrong! Correct Answer: %c\n\n", quiz[i].correctOption);
        }
    }

    printf("Exam Level: %s\n", levelName);
    printf("Final Score: %d/10\n", score);

    // Save best score and give user  feedback
    FILE *hWrite = fopen("C:\\Users\\Hp\\OneDrive\\Desktop\\QuizProject\\QuizProjectV3\\history.txt", "w");
    if (hWrite) {
        fprintf(hWrite, "%d", score);
        fclose(hWrite);
    }

    if (score > prevBest) {
        printf("You are improving! Previous best: %d\n", prevBest);
    } else if (score == prevBest) {
        printf("You matched your previous best: %d\n", prevBest);
    } else {
        printf("Better luck next time! Previous best: %d\n", prevBest);
    }

    // Ask if user wants to see history
    char seeHistory;
    printf("\nDo you want to see your last best score? (Y/N): ");
    if (scanf(" %c", &seeHistory) == 1 && (seeHistory == 'Y' || seeHistory == 'y')) {
        printf("Your last best score was: %d/10\n", prevBest);
    }

    return 0;
}
