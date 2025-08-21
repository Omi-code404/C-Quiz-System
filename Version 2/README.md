# 📘 C Quiz System – Version 2

A **C-based Quiz Application** that lets users take multiple-choice quizzes, view results, and track their performance history.

---

## ✨ Features

* Take quizzes with multiple-choice questions.
* Immediate feedback on answers (✔️ Correct / ❌ Wrong).
* Saves player name and score in `history.txt`.
* View past performance history anytime.
* Paginated display (10 questions per page).

---

## 🛠️ Technologies Used

* **C Language** (Standard C – ANSI/ISO C)
* **File Handling** (`questions.txt` & `history.txt`)
* **Standard Libraries:** `<stdio.h>`, `<stdlib.h>`, `<string.h>`, `<ctype.h>`

---

## ▶️ How to Run

1. Compile the code:

   ```bash
   gcc quiz.c -o quiz
   ```
2. Run the program:

   ```bash
   ./quiz
   ```
3. Select from the menu:

   * `1` → Take Quiz
   * `2` → View History
   * `3` → Exit

---

## 🔮 Future Improvements

* Randomized question order
* Timer for each question
* Difficulty levels (Easy / Medium / Hard)
* Detailed score statistics (percentages, accuracy, etc.)
