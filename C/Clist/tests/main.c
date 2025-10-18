#include <check.h>

#include "clist.h"

#define LIST_AT_VAL(LIST, POS, TYPE) *(TYPE *)list_val(list_atp(LIST, list_front(LIST), POS))

#define LIST_INSERT(LIST, POS, VAL, TYPE) *(TYPE *)list_insert(LIST, POS) = VAL

#define LIST_PUSH_BACK(LIST, VAL, TYPE)   *(TYPE *)list_push_back(LIST)  = VAL
#define LIST_PUSH_FRONT(LIST, VAL, TYPE)  *(TYPE *)list_push_front(LIST) = VAL

START_TEST(clist_insert) {
    const size_t N = 10;
    const size_t DATA_SIZE = sizeof(int);

    Clist *list = list_init(DATA_SIZE);
    ck_assert_int_eq(list_datasize(list), DATA_SIZE);

#if 0
    LIST_INSERT(list, 0, 1, int);
    ck_assert_uint_eq(list_size(list), 1);
    ck_assert_int_eq(LIST_AT_VAL(list, 1, int), 1);

    LIST_INSERT(list, 1, 2, int);
    ck_assert_uint_eq(list_size(list), 2);
    ck_assert_int_eq(LIST_AT_VAL(list, 2, int), 2);
#endif
} END_TEST

START_TEST(clist_push_back) {
    const size_t N = 10;
    const size_t DATA_SIZE = sizeof(int);

    Clist *list = list_init(DATA_SIZE);
    ck_assert_int_eq(list_datasize(list), DATA_SIZE);
    
    LIST_PUSH_BACK(list, 1, int);
    void *it_f_s = list_front(list);
    for (size_t i = 1; i < N; ++i) {
        LIST_PUSH_BACK(list, i+1, int);
        ck_assert_int_eq(LIST_AT_VAL(list, i, int), i+1);
    }
    void *it_f_f = list_front(list);
    ck_assert_ptr_eq(it_f_s, it_f_f);

    ck_assert_uint_eq(list_size(list), N);

    list_destruct(&list);
} END_TEST

START_TEST(clist_push_front) {
    const size_t N = 10;
    const size_t DATA_SIZE = sizeof(int);

    Clist *list = list_init(DATA_SIZE);
    ck_assert_int_eq(list_datasize(list), DATA_SIZE);
    
    LIST_PUSH_FRONT(list, 1, int);
    void *it_f = list_front(list);
    for (int i = 1; i < N; ++i) {
        LIST_PUSH_FRONT(list, i+1,  int);
        ck_assert_int_eq(LIST_AT_VAL(list, 0, int), i+1);
    }
    void *it_b = list_back(list);
    ck_assert_ptr_eq(it_f, it_b);

    ck_assert_uint_eq(list_size(list), N);

    list_destruct(&list);
} END_TEST

START_TEST(clist_swap) {
    const size_t DATA_SIZE = sizeof(int);

    Clist *list = list_init(DATA_SIZE);
    ck_assert_int_eq(list_datasize(list), DATA_SIZE);

    LIST_PUSH_BACK(list, 1, int);
    LIST_PUSH_BACK(list, 2, int);
    ck_assert_int_eq(list_size(list), 2);
   
    int val_f = LIST_AT_VAL(list, 0, int);
    int val_b = LIST_AT_VAL(list, 1, int);

    list_swap(list, list_front(list), list_back(list));
    
    ck_assert_int_eq(val_f, LIST_AT_VAL(list, 1, int));
    ck_assert_int_eq(val_b, LIST_AT_VAL(list, 0, int));
} END_TEST

Suite * clist_suite() {
    Suite *s = suite_create("clist");

    TCase *tc_core = tcase_create("clist");
    tcase_add_test(tc_core, clist_insert);
    tcase_add_test(tc_core, clist_push_back);
    tcase_add_test(tc_core, clist_push_front);
    tcase_add_test(tc_core, clist_swap);

    suite_add_tcase(s, tc_core);

    return s;
}

int main() {
    SRunner *sr = srunner_create(clist_suite());

    srunner_run_all(sr, CK_NORMAL);

    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
