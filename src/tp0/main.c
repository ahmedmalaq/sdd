#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * --- STRUCTURES ---
 * Structures group different data types together.
 */
typedef struct {
    char *name;
    int age;
} Student;

/*
 * --- CALL STACK DEMO ---
 * Let's create a call stack of height 3: main -> first_step -> second_step -> third_step.
 */
void third_step(int x) {
    // BREAKPOINT HERE: Observe the call stack in your debugger
    printf("  [Step 3] Reached with value %d. Look at the \"Call Stack\" panel!\n", x);
}

void second_step(int b) {
    int c = b * 2;
    printf("  [Step 2] Input %d, doubling to %d\n", b, c);
    third_step(c);
}

void first_step(int a) {
    int b = a + 5;
    printf("  [Step 1] Input %d, adding 5 to get %d\n", a, b);
    second_step(b);
}

/*
 * --- CONDITIONS and LOOPS ---
 */
void conditions_loops_demo() {
    printf("\n--- Conditions and Loops ---\n");
    for (int i = 0; i < 5; i++) {
        if (i % 2 == 0) {
            printf("  Iteration %d: Even\n", i);
        } else {
            printf("  Iteration %d: Odd\n", i);
        }
    }
}

/*
 * --- STRINGS ---
 */
void strings_demo() {
    printf("\n--- Strings ---\n");
    char message[] = "Hello";
    char name[20];
    strcpy(name, "C Learner");
    printf("  %s, %s!\n", message, name);
}

/*
 * --- POINTERS (MALLOC, FREE) ---
 */
void pointers_malloc_demo() {
    printf("\n--- Pointers (malloc/free) ---\n");
    int *p = (int *)malloc(sizeof(int));
    if (p == NULL) return;

    *p = 42;
    printf("  Pointer p stores address %p and value %d\n", (void *)p, *p);
    free(p);
}

/*
 * --- STRUCTURES and POINTERS ---
 */
void structures_demo() {
    printf("\n--- Structures ---\n");
    Student s;
    s.name = "Alice";
    s.age = 20;
    printf("  Static struct: %s, age %d\n", s.name, s.age);

    Student *ps = (Student *)malloc(sizeof(Student));
    if (ps != NULL) {
        ps->name = strdup("Bob");
        ps->age = 22;
        printf("  Dynamic struct: %s, age %d\n", ps->name, ps->age);
        free(ps->name);
        free(ps);
    }
}

/*
 * --- DOUBLE POINTERS ---
 */
void double_pointers_demo() {
    printf("\n--- Double Pointers ---\n");
    int count = 3;
    // An array of pointers (double pointer)
    int **array = (int **)malloc(count * sizeof(int *));
    if (array == NULL) return;

    for (int i = 0; i < count; i++) {
        array[i] = (int *)malloc(sizeof(int));
        *array[i] = i * 100;
    }

    for (int i = 0; i < count; i++) {
        printf("  array[%d] points to value %d\n", i, *array[i]);
    }

    // Cleanup: free nested pointers first!
    for (int i = 0; i < count; i++) {
        free(array[i]);
    }
    free(array);
}

int main(int argc, char **argv) {
    (void)argc; (void)argv;
    printf("=== Welcome to the C Debugging Laboratory ===\n");
    printf("Use \"Step Into\" (F11) to explore the functions below.\n");

    conditions_loops_demo();
    strings_demo();
    pointers_malloc_demo();
    structures_demo();
    double_pointers_demo();

    printf("\n--- Stack Trace Demo ---\n");
    first_step(10);

    printf("\n=== Laboratory Finished ===\n");
    return 0;
}

