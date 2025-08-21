#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define BUFFER_SIZE 500
#define QUESTIONS_PER_PAGE 10

struct Quiz {
    char question[BUFFER_SIZE];
    char options[4][BUFFER_SIZE];
    char correctOption;
};

int loadQuestions(struct Quiz quiz[]) {
    FILE *file = fopen("C:\\Users\\Hp\\OneDrive\\Desktop\\questions.txt", "r");
    if (!file) {
        printf("Failed to open questions.txt file!\n");
        return 0;
    }

    int count = 0;
    while (fgets(quiz[count].question, BUFFER_SIZE, file)) {
        quiz[count].question[strcspn(quiz[count].question, "\n")] = '\0';

        for (int i = 0; i < 4; i++) {
            fgets(quiz[count].options[i], BUFFER_SIZE, file);
            quiz[count].options[i][strcspn(quiz[count].options[i], "\n")] = '\0';
        }

        fscanf(file, " %c\n", &quiz[count].correctOption);
        count++;
    }

    fclose(file);
    return count;
}

void saveHistory(char name[], int score, int total) {
    FILE *file = fopen("C:\\Users\\Hp\\OneDrive\\Desktop\\QuizProject\\QuizProjectV2\\history.txt", "a");
    if (!file) {
        printf("Failed to open history.txt file!\n");
        return;
    }
    fprintf(file, "Name: %s, Score: %d/%d\n", name, score, total);
    fclose(file);
}

void viewHistory() {
    FILE *file = fopen("C:\\Users\\Hp\\OneDrive\\Desktop\\QuizProject\\QuizProjectV2\\history.txt", "r");
    if (!file) {
        printf("No history found!\n");
        return;
    }

    char line[200];
    printf("\nPrevious Results:\n");
    printf("----------------------------\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    printf("----------------------------\n");

    fclose(file);
}

int main() {
    int choice;
    printf("==== QUIZ SYSTEM (V2) ====\n");
    printf("1. Take Quiz\n");
    printf("2. View History\n");
    printf("3. Exit\n");
    printf("Enter your choice (1/2/3): ");
    scanf("%d", &choice);
    getchar();

    if (choice == 2) {
        viewHistory();
        return 0;
    } else if (choice == 3) {
        printf("Thank you, come back again!\n");
        return 0;
    }

    struct Quiz quiz[MAX_QUESTIONS];
    char name[50];
    int totalQuestions = loadQuestions(quiz);

    if (totalQuestions == 0) {
        printf("No questions loaded.\n");
        return 1;
    }

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    int score = 0;
    int currentQuestion = 0;
    int questionsAnswered = 0; // Track number of questions answered

    while (currentQuestion < totalQuestions) {
        int questionsToShow = (totalQuestions - currentQuestion >= QUESTIONS_PER_PAGE)
                            ? QUESTIONS_PER_PAGE
                            : totalQuestions - currentQuestion;

        for (int i = currentQuestion; i < currentQuestion + questionsToShow; i++) {
            printf("\nQuestion %d: %s\n", i + 1, quiz[i].question);
            for (int j = 0; j < 4; j++) {
                printf("%s\n", quiz[i].options[j]);
            }

            char answer;
            int validInput = 0;
            do {
                printf("Enter your answer (A/B/C/D): ");
                scanf(" %c", &answer);
                answer = toupper(answer);
                if (answer == 'A' || answer == 'B' || answer == 'C' || answer == 'D') {
                    validInput = 1;
                } else {
                    printf("⚠️ Invalid input! Please enter A, B, C, or D.\n");
                }
            } while (!validInput);

            if (answer == quiz[i].correctOption) {
                printf("Correct answer!\n");
                score++;
            } else {
                printf("Wrong answer! Correct answer: %c\n", quiz[i].correctOption);
            }
            questionsAnswered++; // Increment after each question answered
        }

        currentQuestion += questionsToShow;

        if (currentQuestion < totalQuestions) {
            char continueQuiz;
            printf("\nWould you like to continue with the next set of questions? (Y/N): ");
            scanf(" %c", &continueQuiz);
            continueQuiz = toupper(continueQuiz);
            if (continueQuiz != 'Y') {
                break;
            }
        }
    }

    printf("\n%s, your total score: %d/%d\n", name, score, questionsAnswered);

    saveHistory(name, score, questionsAnswered);
    printf(" Your result has been saved to history.txt.\n");
printf("\nTotal Questions Available: %d\n", totalQuestions);
    return 0;
}
