# MCQ Quiz Game - Version 3

A fun C programming quiz application that tests your knowledge with randomized questions across different difficulty levels. I built this to practice file handling and randomization algorithms while creating something actually useful for learning.

## What It Does

- **Take random quizzes** with 10 questions each from Easy, Medium, or Hard difficulty
- **Shuffles questions** so you never get the same order twice
- **Instant feedback** after each answer - shows if you got it right immediately
- **Tracks your best scores** automatically in a history file
- **Compares your performance** with previous attempts
- **Case-insensitive input** - just press A, B, C, or D (uppercase or lowercase)

## What I Used to Build It

- **Plain C language** - keeping it simple and efficient
- **File handling** for questions and score history
- **Standard libraries**: stdio.h, stdlib.h, string.h, time.h
- **Fisher-Yates shuffle** algorithm for proper randomization
- **Structures and arrays** to organize the questions

## Files You'll Need

```
mcq-quiz-game/
├── quiz.c              # Main program
├── easy.txt            # Easy questions (you create this)
├── medium.txt          # Medium questions  
├── hard.txt            # Hard questions
├── history.txt         # Auto-created score file
└── README.md           # This instructions file
```

## Getting Started

**First, compile it:**
```bash
gcc -o quiz quiz.c
```

**Then run:**
```bash
./quiz        # On Linux/macOS
quiz.exe      # On Windows
```

## Setting Up Your Questions

You need to create the question files (`easy.txt`, `medium.txt`, `hard.txt`) with this exact format:

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

**Important formatting rules:**
- Question on the first line
- Four options labeled A), B), C), D)
- Correct answer as single letter (A-D) on line after options
- Blank line between questions

## How to Play

1. **Choose your difficulty** - Easy (1), Medium (2), or Hard (3)
2. **Answer 10 random questions** from that difficulty level
3. **Get immediate feedback** after each answer
4. **See your final score** and compare with your personal best
5. **Check your progress** by viewing past performance

## What You'll See

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

## What Makes This Version Special

I built this as an improvement over previous versions - here's what's new:

### Version 1 vs What We Have Now
| Feature | Old Version | Current Version |
|---------|-------------|-----------------|
| Questions | Hardcoded in code | Separate text files |
| Order | Always same order | Random every time |
| Difficulty | Only one level | Easy/Medium/Hard |
| Scores | Didn't save | Remembers your best |
| Experience | Pretty basic | Helpful feedback |

### Version 2 vs Current Version
| Feature | Version 2 | Version 3 |
|---------|-----------|-----------|
| Question Order | Fixed sequence | Completely random |
| Difficulty | Just one level | Three choices |
| Score Memory | Only current session | Keeps history |
| Replay Value | Got repetitive | Fresh every time |

### Why This Version is Better:
- 🎲 **Never the same quiz twice** - questions shuffle randomly
- 🎯 **Choose your challenge** - pick the right difficulty
- 💾 **Remembers your progress** - tracks improvement
- 🏆 **Motivational feedback** - encourages you to beat your best
- 🔄 **Always fresh** - random selection keeps it interesting


## Technical Stuff Under the Hood

- **Memory efficient** - uses static allocation with safety checks
- **Error handling** - deals with missing files gracefully
- **Proper randomization** - implements Fisher-Yates shuffle correctly
- **Clean code** - well-organized functions
- **Works everywhere** - tested on Windows, Linux, and macOS

## Ideas for Future Improvements

- ✅ **Random questions** - already working!
- ✅ **Difficulty levels** - implemented!
- ⏱️ **Add timers** for each question
- 📊 **More detailed stats** - percentages, trends
- 👥 **Multiple user support** - different profiles
- 🏆 **Achievements system** - badges for milestones
