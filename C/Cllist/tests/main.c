#include <check.h>
#include <stdio.h>

#include "cllist.h"

#define DATA_TYPE int

#define CLLIST_PUSH_BACK(CLLIST, VAL, TYPE) *(TYPE *)llist_push_back(CLLIST) = VAL
#define CLLIST_PUSH_FRONT(CLLIST, VAL, TYPE) *(TYPE *)llist_push_front(CLLIST) = VAL

START_TEST(cllist_default) {
    const size_t DATA_SIZE = sizeof(DATA_SIZE);

    Cllist *llist = llist_init(DATA_SIZE);
    ck_assert_int_eq(llist_datasize(llist), DATA_SIZE);
    ck_assert_int_eq(llist_size(llist), 0);

    llist_destruct(&llist);
    ck_assert_ptr_eq(llist, NULL);
} END_TEST

START_TEST(cllist_insert) {
    const size_t DATA_SIZE = sizeof(DATA_TYPE);

    Cllist *llist = llist_init(DATA_SIZE);
    ck_assert_int_eq(llist_datasize(llist), DATA_SIZE);
    ck_assert_int_eq(llist_size(llist), 0);
    
    *(DATA_TYPE *)llist_insert(llist, 0) = 1;
    ck_assert_int_eq(*(int *)llist_val(llist_front(llist)), 1);

    *(DATA_TYPE *)llist_insert(llist, 0) = 2;
    ck_assert_int_eq(*(int *)llist_val(llist_front(llist)), 2);

    *(DATA_TYPE *)llist_insert(llist, 2) = 3;
    ck_assert_int_eq(*(int *)llist_val(llist_back(llist)), 3);

    *(DATA_TYPE *)llist_insert(llist, 1) = 4;
    ck_assert_int_eq(*(int *)llist_val(llist_atp(llist, 1)), 4);

    DATA_TYPE *ptr = (DATA_TYPE *)llist_insert(llist, llist_size(llist)+1);
    ck_assert_ptr_eq(ptr, NULL);

    llist_destruct(&llist);
    ck_assert_ptr_eq(llist, NULL);
} END_TEST

START_TEST(cllist_erase) {
    const size_t N = 10;
    const size_t DATA_SIZE = sizeof(DATA_TYPE);

    Cllist *llist = llist_init(DATA_SIZE);
    ck_assert_int_eq(llist_datasize(llist), DATA_SIZE);
    ck_assert_int_eq(llist_size(llist), 0);

    for (size_t i = 0; i < N; ++i) {
        CLLIST_PUSH_BACK(llist, i, DATA_TYPE);
    }
    ck_assert_int_eq(llist_size(llist), N);

    llist_erase(llist, 0);
    ck_assert_int_eq(llist_size(llist), N-1);
    ck_assert_int_eq(*(int *)llist_val(llist_atp(llist, 0)), 1);

    llist_erase(llist, N-1);
    ck_assert_int_eq(llist_size(llist), N-2);
    ck_assert_int_eq(*(int *)llist_val(llist_atp(llist, N-3)), 8);

    llist_erase(llist, 1);
    ck_assert_int_eq(llist_size(llist), N-3);
    ck_assert_int_eq(*(int *)llist_val(llist_atp(llist, 1)), 3);

    llist_destruct(&llist);
    ck_assert_ptr_eq(llist, NULL);
} END_TEST

START_TEST(cllist_push_back) {
    const size_t N = 10;
    const size_t DATA_SIZE = sizeof(DATA_TYPE);

    Cllist *llist = llist_init(DATA_SIZE);
    ck_assert_int_eq(llist_datasize(llist), DATA_SIZE);
    ck_assert_int_eq(llist_size(llist), 0);

    for (size_t i = 0; i < N; ++i) {
        CLLIST_PUSH_BACK(llist, i, DATA_TYPE);
    }
    ck_assert_int_eq(llist_size(llist), N);

    llist_destruct(&llist);
    ck_assert_ptr_eq(llist, NULL);
} END_TEST

START_TEST(cllist_pop_back) {
    const size_t N = 10;
    const size_t DATA_SIZE = sizeof(DATA_TYPE);

    Cllist *llist = llist_init(DATA_SIZE);
    ck_assert_int_eq(llist_datasize(llist), DATA_SIZE);
    ck_assert_int_eq(llist_size(llist), 0);

    for (size_t i = 0; i < N; ++i) {
        CLLIST_PUSH_BACK(llist, i, int);
    }
    ck_assert_int_eq(llist_size(llist), N);

    for (size_t i = 0; i < 10; ++i) {
        llist_pop_back(llist);
    }
    ck_assert_int_eq(llist_size(llist), 0);
    ck_assert_ptr_eq(llist_front(llist), NULL);
    ck_assert_ptr_eq(llist_back(llist), NULL);

    llist_destruct(&llist);
    ck_assert_ptr_eq(llist, NULL);
} END_TEST

START_TEST(cllist_push_front) {
    const size_t N = 10;
    const size_t DATA_SIZE = sizeof(DATA_TYPE);

    Cllist *llist = llist_init(DATA_SIZE);
    ck_assert_int_eq(llist_datasize(llist), DATA_SIZE);
    ck_assert_int_eq(llist_size(llist), 0);

    for (size_t i = 0; i < N; ++i) {
        CLLIST_PUSH_FRONT(llist, i, int);
    }
    ck_assert_int_eq(llist_size(llist), N);

    llist_destruct(&llist);
    ck_assert_ptr_eq(llist, NULL);
} END_TEST

START_TEST(cllist_pop_front) {
    const size_t N = 10;
    const size_t DATA_SIZE = sizeof(DATA_TYPE);

    Cllist *llist = llist_init(DATA_SIZE);
    ck_assert_int_eq(llist_datasize(llist), DATA_SIZE);
    ck_assert_int_eq(llist_size(llist), 0);

    for (size_t i = 0; i < N; ++i) {
        CLLIST_PUSH_BACK(llist, i, int);
    }
    ck_assert_int_eq(llist_size(llist), N);

    for (size_t i = 0; i < 10; ++i) {
        llist_pop_front(llist);
    }
    ck_assert_int_eq(llist_size(llist), 0);
    ck_assert_ptr_eq(llist_front(llist), NULL);
    ck_assert_ptr_eq(llist_back(llist), NULL);

    llist_destruct(&llist);
    ck_assert_ptr_eq(llist, NULL);
} END_TEST

START_TEST(cllist_clear) {
    const size_t N = 10;
    const size_t DATA_SIZE = sizeof(DATA_TYPE);

    Cllist *llist = llist_init(DATA_SIZE);
    ck_assert_int_eq(llist_datasize(llist), DATA_SIZE);
    ck_assert_int_eq(llist_size(llist), 0);

    for (size_t i = 0; i < N; ++i) {
        CLLIST_PUSH_BACK(llist, i, int);
    }
    ck_assert_int_eq(llist_size(llist), N);

    llist_clear(llist);
    ck_assert_int_eq(llist_size(llist), 0);

    llist_destruct(&llist);
    ck_assert_ptr_eq(llist, NULL);
} END_TEST

START_TEST(cllist_prev) {
    const size_t N = 10;
    const size_t DATA_SIZE = sizeof(DATA_TYPE);

    Cllist *llist = llist_init(DATA_SIZE);
    ck_assert_int_eq(llist_datasize(llist), DATA_SIZE);
    ck_assert_int_eq(llist_size(llist), 0);

    for (size_t i = 0; i < N; ++i) {
        CLLIST_PUSH_BACK(llist, i, DATA_TYPE);
    }
    ck_assert_int_eq(llist_size(llist), N);

    iter it = llist_back(llist);
    iter it_prev = llist_prev(llist, it);
    ck_assert_ptr_eq(llist_atp(llist, N-2), it_prev);

    llist_destruct(&llist);
    ck_assert_ptr_eq(llist, NULL);
} END_TEST

START_TEST(cllist_next) {
    const size_t N = 10;
    const size_t DATA_SIZE = sizeof(DATA_TYPE);

    Cllist *llist = llist_init(DATA_SIZE);
    ck_assert_int_eq(llist_datasize(llist), DATA_SIZE);
    ck_assert_int_eq(llist_size(llist), 0);

    for (size_t i = 0; i < N; ++i) {
        CLLIST_PUSH_BACK(llist, i, DATA_TYPE);
    }
    ck_assert_int_eq(llist_size(llist), N);

    iter it = llist_front(llist);
    iter it_next = llist_next(it);
    ck_assert_ptr_eq(llist_atp(llist, 1), it_next);

    llist_destruct(&llist);
    ck_assert_ptr_eq(llist, NULL);
} END_TEST

Suite *cllist_suite() {
    Suite *s = suite_create("cllist");

    TCase *tc_core = tcase_create("cllist");
    tcase_add_test(tc_core, cllist_default);
    tcase_add_test(tc_core, cllist_clear);
    tcase_add_test(tc_core, cllist_insert);
    tcase_add_test(tc_core, cllist_erase);
    tcase_add_test(tc_core, cllist_push_back);
    tcase_add_test(tc_core, cllist_pop_back);
    tcase_add_test(tc_core, cllist_push_front);
    tcase_add_test(tc_core, cllist_pop_front);
    tcase_add_test(tc_core, cllist_prev);
    tcase_add_test(tc_core, cllist_next);

    suite_add_tcase(s, tc_core);

    return s;
}

int main() {
    SRunner *sr = srunner_create(cllist_suite());

    srunner_run_all(sr, CK_NORMAL);

    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
