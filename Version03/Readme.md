#  MCQ Quiz Game - Version 3

A C-based Quiz Application that presents 10 randomized multiple-choice questions with difficulty levels, tracks performance history, and provides immediate feedback with score comparison.

## ✨ Features

- **Take quizzes with multiple-choice questions** from 3 difficulty levels (Easy/Medium/Hard)
- **Randomized question selection** - No two quiz sessions are the same
- **Immediate feedback on answers** (✅ Correct / ❌ Wrong with correct answer shown)
- **Difficulty level selection** - Choose Easy, Medium, or Hard questions
- **Saves best score in history.txt** with performance tracking
- **View past performance history** anytime with comparison feedback
- **10 questions per quiz session** - Perfect bite-sized learning
- **Case-insensitive input** - Accepts both A/a, B/b, C/c, D/d
- **Motivational feedback** - Encouraging messages based on improvement

## 🛠 Technologies Used

- **C Language** (Standard C – ANSI/ISO C)
- **File Handling** (easy.txt, medium.txt, hard.txt & history.txt)
- **Standard Libraries**: `<stdio.h>`, `<stdlib.h>`, `<string.h>`, `<time.h>`
- **Algorithms**: Fisher-Yates shuffle for randomization
- **Data Structures**: Structures, arrays, and string manipulation

## 📁 File Structure

```
mcq-quiz-game/
├── quiz.c              # Main program file
├── easy.txt            # Easy level questions
├── medium.txt          # Medium level questions  
├── hard.txt            # Hard level questions
├── history.txt         # Auto-generated score history
└── README.md           # This file
```

## ▶️ How to Run

**Compile the code:**
```bash
gcc -o quiz quiz.c
```

**Run the program:**
```bash
./quiz        # Linux/macOS
quiz.exe      # Windows
```

## 📝 Question File Format

Create your question files (`easy.txt`, `medium.txt`, `hard.txt`) with this format:

```
What is the capital of France?
A) London
B) Berlin
C) Paris
D) Madrid
C

Which programming language is this written in?
A) Python
B) Java
C) C
D) JavaScript
C

```

**Format Rules:**
- Question text on first line
- Four options starting with A), B), C), D)
- Correct answer as single letter (A, B, C, or D)
- Empty line between questions

## 🎮 How It Works

1. **Select Difficulty**: Choose Easy (1), Medium (2), or Hard (3)
2. **Random Selection**: Program shuffles and picks 10 questions from chosen level
3. **Interactive Quiz**: Answer each question with A, B, C, or D
4. **Instant Feedback**: See if you're correct immediately
5. **Score Tracking**: Your best score is saved and compared
6. **Performance Review**: View improvement over time

## 📊 Sample Output

```
=== MCQ Quiz Game (Version 3: Random Questions) ===
Choose difficulty level:
1. Easy
2. Medium
3. Hard
Enter your choice (1-3): 2

Exam Level: Medium
Total Questions: 10

Q1: What is the time complexity of binary search?
A) O(1)
B) O(log n)
C) O(n)
D) O(n²)
Your Answer (A/B/C/D): B
✅ Correct!

Exam Level: Medium
🎯 Final Score: 8/10
✨ You are improving! Previous best: 6

Do you want to see your last best score? (Y/N): y
📜 Your last best score was: 6/10
```

## 🔮 Future Improvements

- ✅ **Randomized question order** (Already implemented!)
- ✅ **Difficulty levels (Easy/Medium/Hard)** (Already implemented!)
- ⏱️ **Timer for each question**
- 📊 **Detailed score statistics** (percentages, accuracy trends)
- 👥 **Multiple user profiles** with separate histories
- 🏆 **Achievement system** and badges
- 📱 **Cross-platform GUI interface**

## 🚀 Why This Version is Better Than Previous Versions

### **Version 1 vs Version 3**
| Feature | Version 1 | Version 3 |
|---------|-----------|-----------|
| Question Storage | ❌ Hardcoded | ✅ External files |
| Question Order | ❌ Always same | ✅ Random selection |
| Difficulty Levels | ❌ None | ✅ Easy/Medium/Hard |
| Score History | ❌ No tracking | ✅ Best score saved |
| User Experience | ❌ Basic | ✅ Interactive feedback |

### **Version 2 vs Version 3**
| Feature | Version 2 | Version 3 |
|---------|-----------|-----------|
| Question Order | ❌ Sequential | ✅ Randomized |
| Difficulty Options | ❌ Single level | ✅ 3 difficulty levels |
| Score Tracking | ❌ Session only | ✅ Persistent history |
| Replayability | ❌ Predictable | ✅ Different every time |
| User Choice | ❌ No options | ✅ Difficulty selection |

### **Key Improvements in Version 3:**
- 🎲 **Randomization Engine**: No memorizing question sequences
- 🎯 **Difficulty Scaling**: Choose your challenge level
- 💾 **Smart Persistence**: Remembers your best performance
- 🏆 **Progress Tracking**: Motivational feedback system
- 🔄 **Infinite Replayability**: Random selection keeps it fresh
- ⚡ **Enhanced UX**: Better prompts and visual feedback

## 🎓 Perfect for

- **Students**: Self-assessment and exam preparation
- **Teachers**: Quick classroom quizzes
- **Developers**: C programming portfolio project
- **Learning**: Understanding file I/O, algorithms, and data structures

## 👨‍💻 Technical Highlights

- **Memory Efficient**: Static allocation with bounds checking
- **Error Handling**: Graceful file and input validation
- **Algorithm Implementation**: Fisher-Yates shuffle algorithm
- **Modular Design**: Clean function separation
- **Cross-Platform**: Works on Windows, Linux, macOS
--
