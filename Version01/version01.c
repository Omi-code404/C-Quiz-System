#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Define maximum number of questions and questions to ask in one quiz
#define MAX_QUESTIONS 18
#define QUESTIONS_TO_ASK 8

// Structure to store question data
struct Question {
    char question[200];        // Stores the question text
    char options[4][100];      // Stores the four answer options
    char correctOption;        // Stores the correct option (A, B, C, or D)
};

// Function to display a question and its options
void displayQuestion(struct Question q, int questionNumber) {
    printf("Question %d: %s\n", questionNumber, q.question);
    for (int i = 0; i < 4; i++) {
        printf("%s\n", q.options[i]);
    }
}

// Function to check if the user's answer is correct
int checkAnswer(struct Question q, char answer) {
    return (answer == q.correctOption || answer == q.correctOption + 32);
}

// Function to load all questions into the quiz array
void loadQuestions(struct Question quiz[]) {
    // Question 1
    strcpy(quiz[0].question, "What is the capital of Bangladesh?");
    strcpy(quiz[0].options[0], "A) Dhaka");
    strcpy(quiz[0].options[1], "B) Chittagong");
    strcpy(quiz[0].options[2], "C) Khulna");
    strcpy(quiz[0].options[3], "D) Barisal");
    quiz[0].correctOption = 'A';

    // Question 2
    strcpy(quiz[1].question, "Who is considered the father of the computer?");
    strcpy(quiz[1].options[0], "A) Bill Gates");
    strcpy(quiz[1].options[1], "B) Charles Babbage");
    strcpy(quiz[1].options[2], "C) Steve Jobs");
    strcpy(quiz[1].options[3], "D) Alan Turing");
    quiz[1].correctOption = 'B';

    // Question 3
    strcpy(quiz[2].question, "Who is the creator of the C programming language?");
    strcpy(quiz[2].options[0], "A) Dennis Ritchie");
    strcpy(quiz[2].options[1], "B) Brian Kernighan");
    strcpy(quiz[2].options[2], "C) Ken Thompson");
    strcpy(quiz[2].options[3], "D) Guido van Rossum");
    quiz[2].correctOption = 'A';

    // Question 4
    strcpy(quiz[3].question, "Which is the largest ocean on Earth?");
    strcpy(quiz[3].options[0], "A) Atlantic Ocean");
    strcpy(quiz[3].options[1], "B) Pacific Ocean");
    strcpy(quiz[3].options[2], "C) Indian Ocean");
    strcpy(quiz[3].options[3], "D) Arctic Ocean");
    quiz[3].correctOption = 'B';

    // Question 5
    strcpy(quiz[4].question, "Who created the Python programming language?");
    strcpy(quiz[4].options[0], "A) Guido van Rossum");
    strcpy(quiz[4].options[1], "B) Larry Wall");
    strcpy(quiz[4].options[2], "C) Dennis Ritchie");
    strcpy(quiz[4].options[3], "D) Brendan Eich");
    quiz[4].correctOption = 'A';

    // Question 6
    strcpy(quiz[5].question, "What is the average distance from Earth to the Sun?");
    strcpy(quiz[5].options[0], "A) 150 million km");
    strcpy(quiz[5].options[1], "B) 120 million km");
    strcpy(quiz[5].options[2], "C) 180 million km");
    strcpy(quiz[5].options[3], "D) 100 million km");
    quiz[5].correctOption = 'A';

    // Question 7
    strcpy(quiz[6].question, "What is the national flower of Bangladesh?");
    strcpy(quiz[6].options[0], "A) Rose");
    strcpy(quiz[6].options[1], "B) Water Lily");
    strcpy(quiz[6].options[2], "C) Jasmine");
    strcpy(quiz[6].options[3], "D) Marigold");
    quiz[6].correctOption = 'B';

    // Question 8
    strcpy(quiz[7].question, "In C programming, which library provides the printf() function?");
    strcpy(quiz[7].options[0], "A) stdlib.h");
    strcpy(quiz[7].options[1], "B) string.h");
    strcpy(quiz[7].options[2], "C) stdio.h");
    strcpy(quiz[7].options[3], "D) time.h");
    quiz[7].correctOption = 'C';

    // Question 9
    strcpy(quiz[8].question, "What is the highest mountain peak in the world?");
    strcpy(quiz[8].options[0], "A) Mount Kilimanjaro");
    strcpy(quiz[8].options[1], "B) Mount Everest");
    strcpy(quiz[8].options[2], "C) Mount McKinley");
    strcpy(quiz[8].options[3], "D) Mount Fuji");
    quiz[8].correctOption = 'B';

    // Question 10
    strcpy(quiz[9].question, "Who invented the World Wide Web?");
    strcpy(quiz[9].options[0], "A) Tim Berners-Lee");
    strcpy(quiz[9].options[1], "B) Steve Jobs");
    strcpy(quiz[9].options[2], "C) Elon Musk");
    strcpy(quiz[9].options[3], "D) Mark Zuckerberg");
    quiz[9].correctOption = 'A';

    // Question 11
    strcpy(quiz[10].question, "When is Bangladesh's Independence Day?");
    strcpy(quiz[10].options[0], "A) 16 December");
    strcpy(quiz[10].options[1], "B) 26 March");
    strcpy(quiz[10].options[2], "C) 14 November");
    strcpy(quiz[10].options[3], "D) 21 February");
    quiz[10].correctOption = 'B';

    // Question 12
    strcpy(quiz[11].question, "In C programming, what is the starting index of an array?");
    strcpy(quiz[11].options[0], "A) 1");
    strcpy(quiz[11].options[1], "B) 0");
    strcpy(quiz[11].options[2], "C) -1");
    strcpy(quiz[11].options[3], "D) 2");
    quiz[11].correctOption = 'B';

    // Question 13
    strcpy(quiz[12].question, "Which is the largest desert in the world?");
    strcpy(quiz[12].options[0], "A) Sahara Desert");
    strcpy(quiz[12].options[1], "B) Gobi Desert");
    strcpy(quiz[12].options[2], "C) Kalahari Desert");
    strcpy(quiz[12].options[3], "D) Antarctic Desert");
    quiz[12].correctOption = 'D';

    // Question 14
    strcpy(quiz[13].question, "Which gas is most abundant in Earth's atmosphere?");
    strcpy(quiz[13].options[0], "A) Oxygen");
    strcpy(quiz[13].options[1], "B) Nitrogen");
    strcpy(quiz[13].options[2], "C) Carbon Dioxide");
    strcpy(quiz[13].options[3], "D) Hydrogen");
    quiz[13].correctOption = 'B';

    // Question 15
    strcpy(quiz[14].question, "Who wrote the national anthem of Bangladesh?");
    strcpy(quiz[14].options[0], "A) Kazi Nazrul Islam");
    strcpy(quiz[14].options[1], "B) Rabindranath Tagore");
    strcpy(quiz[14].options[2], "C) Jibanananda Das");
    strcpy(quiz[14].options[3], "D) Michael Madhusudan Dutt");
    quiz[14].correctOption = 'B';

    // Question 16
    strcpy(quiz[15].question, "What is the smallest unit of data in a computer?");
    strcpy(quiz[15].options[0], "A) Byte");
    strcpy(quiz[15].options[1], "B) Bit");
    strcpy(quiz[15].options[2], "C) Kilobyte");
    strcpy(quiz[15].options[3], "D) Megabyte");
    quiz[15].correctOption = 'B';

    // Question 17
    strcpy(quiz[16].question, "Which planet is known as the Red Planet?");
    strcpy(quiz[16].options[0], "A) Jupiter");
    strcpy(quiz[16].options[1], "B) Mars");
    strcpy(quiz[16].options[2], "C) Venus");
    strcpy(quiz[16].options[3], "D) Mercury");
    quiz[16].correctOption = 'B';

    // Question 18
    strcpy(quiz[17].question, "What is the chemical symbol for water?");
    strcpy(quiz[17].options[0], "A) H2O");
    strcpy(quiz[17].options[1], "B) CO2");
    strcpy(quiz[17].options[2], "C) O2");
    strcpy(quiz[17].options[3], "D) N2");
    quiz[17].correctOption = 'A';
}

// Main function to run the quiz
int main() {
    // Initialize random seed for question selection
    srand(time(NULL));

    struct Question quiz[MAX_QUESTIONS];
    int score = 0;
    int askedQuestions[QUESTIONS_TO_ASK];
    int questionCount = 0;

    // Load all questions
    loadQuestions(quiz);

    // Initialize array to track asked questions
    for (int i = 0; i < QUESTIONS_TO_ASK; i++) {
        askedQuestions[i] = -1;
    }

    printf("=== MCQ Quiz Game ===\n\n");

    // Ask QUESTIONS_TO_ASK random questions
    while (questionCount < QUESTIONS_TO_ASK) {
        // Select a random question
        int randomIndex = rand() % MAX_QUESTIONS;
        int alreadyAsked = 0;

        // Check if the question was already asked
        for (int i = 0; i < questionCount; i++) {
            if (askedQuestions[i] == randomIndex) {
                alreadyAsked = 1;
                break;
            }
        }

        // If not asked, display the question
        if (!alreadyAsked) {
            askedQuestions[questionCount] = randomIndex;
            displayQuestion(quiz[randomIndex], questionCount + 1);

            char answer;
            printf("Enter your answer (A/B/C/D): ");
            scanf(" %c", &answer);

            // Validate input
            if (answer >= 'A' && answer <= 'D' || answer >= 'a' && answer <= 'd') {
                if (checkAnswer(quiz[randomIndex], answer)) {
                    printf("Correct answer!\n\n");
                    score++;
                } else {
                    printf("Incorrect answer! Correct answer: %c\n\n", quiz[randomIndex].correctOption);
                }
                questionCount++;
            } else {
                printf("Invalid input! Please enter A, B, C, or D.\n\n");
            }
        }
    }

    // Display final score
    printf("Quiz completed! Your total score: %d/%d\n", score, QUESTIONS_TO_ASK);

    return 0;
}
