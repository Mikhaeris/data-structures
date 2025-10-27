#include <check.h>
#include <stdlib.h>

#include "cstack.h"

START_TEST(cstack_init) {
    const size_t N = 10;
    const size_t DATA_SIZE = sizeof(int);

    Cstack *stack = stack_init(0, DATA_SIZE);
    ck_assert_int_eq(stack_datasize(stack), DATA_SIZE);
    ck_assert_int_eq(stack_size(stack), 0);

    stack_destruct(&stack);
    ck_assert_ptr_eq(stack, NULL);
} END_TEST

START_TEST(cstack_default) {
    const size_t N = 10;
    const size_t DATA_SIZE = sizeof(int);

    Cstack *stack = stack_init(0, DATA_SIZE);
    ck_assert_int_eq(stack_datasize(stack), DATA_SIZE);
    ck_assert_int_eq(stack_size(stack), 0);
    for (size_t i = 0; i < N; ++i) {
        *(int *)stack_push(stack) = i+1;
    }
    ck_assert_int_eq(stack_size(stack), N);

    for (size_t i = 0; i < N; ++i) {
        stack_pop(stack);
    }
    ck_assert_int_eq(stack_size(stack), 0);

    stack_destruct(&stack);
    ck_assert_ptr_eq(stack, NULL);
} END_TEST

START_TEST(cstack_swap) {
    const size_t N1 = 10;
    const size_t DATA_SIZE1 = sizeof(int);

    Cstack *stack1 = stack_init(0, DATA_SIZE1);
    ck_assert_int_eq(stack_datasize(stack1), DATA_SIZE1);
    ck_assert_int_eq(stack_size(stack1), 0);

    for (size_t i = 0; i < N1; ++i) {
        *(int *)stack_push(stack1) = i+1;
    }
    ck_assert_int_eq(stack_size(stack1), N1);


    const size_t N2 = 20;
    const size_t DATA_SIZE2 = sizeof(double);

    Cstack *stack2 = stack_init(0, DATA_SIZE2);
    ck_assert_int_eq(stack_datasize(stack2), DATA_SIZE2);
    ck_assert_int_eq(stack_size(stack2), 0);

    double num = 1.1;
    for (size_t i = 0; i < N2; ++i) {
        *(int *)stack_push(stack2) = num;
        num += i;
    }
    ck_assert_int_eq(stack_size(stack2), N2);

    stack_swap(stack1, stack2);

    ck_assert_int_eq(stack_datasize(stack1), DATA_SIZE2);
    ck_assert_int_eq(stack_size(stack1), N2);
    
    ck_assert_int_eq(stack_datasize(stack2), DATA_SIZE1);
    ck_assert_int_eq(stack_size(stack2), N1);

    stack_destruct(&stack1);
    stack_destruct(&stack2);
} END_TEST

Suite * cstack_suite() {
    Suite *s = suite_create("cstack");

    TCase *tc_core = tcase_create("cstack");
    tcase_add_test(tc_core, cstack_init);
    tcase_add_test(tc_core, cstack_default);
    tcase_add_test(tc_core, cstack_swap);

    suite_add_tcase(s, tc_core);

    return s;
}

int main() {
    SRunner *sr = srunner_create(cstack_suite());

    srunner_run_all(sr, CK_NORMAL);

    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
