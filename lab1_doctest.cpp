#define DOCTEST_CONFIG_IMPLEMENT

#include "libs/doctest.h"
#include "lists/ArrayList.h"
#include "lists/LinkedList.h"
#include "lists/VectorList.h"
#include "sorts/sorts.h"
#include "compare_functions/compare.h"

TEST_CASE ("[Integer] ArrayList") {
    std::stringstream ss;

    ArrayList<int> list;
            CHECK(list.get_size() == 0);

            CHECK_THROWS_AS(list.get(0), std::out_of_range);
            CHECK_THROWS_AS(list.get(10), std::out_of_range);
            CHECK_THROWS_AS(list.get(-1), std::out_of_range);

            CHECK_THROWS_AS(list.remove(0), std::out_of_range);
            CHECK_THROWS_AS(list.remove(10), std::out_of_range);
            CHECK_THROWS_AS(list.remove(-1), std::out_of_range);

            CHECK(list.find(0) == -1);

    list.add(4);
    list.add(2);
    list.add(1);
    ss << list;
            CHECK(ss.str() == "[4, 2, 1]");
    ss.str("");

    list.add(3, 1);
    ss << list;
            CHECK(ss.str() == "[4, 3, 2, 1]");
    ss.str("");

    list.add(5, -1); //when index < 0 -> index = last
    list.add(6, 2);
    list.add(7, 0);
    list.add(8, -5);
    ss << list;
            CHECK(ss.str() == "[7, 4, 3, 6, 2, 1, 5, 8]");
    ss.str("");

            CHECK(list.get_size() == 8);

    list.remove(0);
    list.remove(-1);
    list.remove(2);
    ss << list;
            CHECK(ss.str() == "[4, 3, 2, 1, 5]");
    ss.str("");

            CHECK(list.get_size() == 5);

            CHECK(list.get(0) == 4);
            CHECK(list.get(2) == 2);
            CHECK(list.get(-1) == 5);
            CHECK_THROWS_AS(list.get(10), std::out_of_range);

            CHECK(list.find(4) == 0);
            CHECK(list.find(2) == 2);
            CHECK(list.find(5) == 4);
            CHECK(list.find(8) == -1);

            CHECK_THROWS_AS(list.add(0, 10), std::out_of_range);
            CHECK_THROWS_AS(list.remove(10), std::out_of_range);

            SUBCASE("Bubble sort") {
        list.sort(bubble_sort);
        ss << list;
                CHECK(ss.str() == "[1, 2, 3, 4, 5]");
        ss.str("");

        list.sort(bubble_sort, compare_int_reverse);
        ss << list;
                CHECK(ss.str() == "[5, 4, 3, 2, 1]");
        ss.str("");
    }

            SUBCASE("Insertion sort") {
        list.sort(insertion_sort);
        ss << list;
                CHECK(ss.str() == "[1, 2, 3, 4, 5]");
        ss.str("");

        list.sort(insertion_sort, compare_int_reverse);
        ss << list;
                CHECK(ss.str() == "[5, 4, 3, 2, 1]");
        ss.str("");
    }

            SUBCASE("Merge sort") {
        list.sort(merge_sort);
        ss << list;
                CHECK(ss.str() == "[1, 2, 3, 4, 5]");
        ss.str("");

        list.sort(merge_sort, compare_int_reverse);
        ss << list;
                CHECK(ss.str() == "[5, 4, 3, 2, 1]");
        ss.str("");
    }

            SUBCASE("Quick sort") {
        list.sort(quick_sort);
        ss << list;
                CHECK(ss.str() == "[1, 2, 3, 4, 5]");
        ss.str("");

        list.sort(quick_sort, compare_int_reverse);
        ss << list;
                CHECK(ss.str() == "[5, 4, 3, 2, 1]");
        ss.str("");
    }

    list.clear();
    ss << list;
            CHECK(list.get_size() == 0);
            CHECK(ss.str() == "[]");
}

TEST_CASE ("[Integer] LinkedList") {
    std::stringstream ss;

    LinkedList<int> list;
            CHECK(list.get_size() == 0);

            CHECK_THROWS_AS(list.get(0), std::out_of_range);
            CHECK_THROWS_AS(list.get(10), std::out_of_range);
            CHECK_THROWS_AS(list.get(-1), std::out_of_range);

            CHECK_THROWS_AS(list.remove(0), std::out_of_range);
            CHECK_THROWS_AS(list.remove(10), std::out_of_range);
            CHECK_THROWS_AS(list.remove(-1), std::out_of_range);

            CHECK(list.find(0) == -1);

    list.add(4);
    list.add(2);
    list.add(1);
    ss << list;
            CHECK(ss.str() == "[4, 2, 1]");
    ss.str("");

    list.add(3, 1);
    ss << list;
            CHECK(ss.str() == "[4, 3, 2, 1]");
    ss.str("");

    list.add(5, -1); //when index < 0 -> index = last
    list.add(6, 2);
    list.add(7, 0);
    list.add(8, -5);
    ss << list;
            CHECK(ss.str() == "[7, 4, 3, 6, 2, 1, 5, 8]");
    ss.str("");

            CHECK(list.get_size() == 8);

    list.remove(0);
    list.remove(-1);
    list.remove(2);
    ss << list;
            CHECK(ss.str() == "[4, 3, 2, 1, 5]");
    ss.str("");

            CHECK(list.get_size() == 5);

            CHECK(list.get(0) == 4);
            CHECK(list.get(2) == 2);
            CHECK(list.get(-1) == 5);
            CHECK_THROWS_AS(list.get(10), std::out_of_range);

            CHECK(list.find(4) == 0);
            CHECK(list.find(2) == 2);
            CHECK(list.find(5) == 4);
            CHECK(list.find(8) == -1);

            CHECK_THROWS_AS(list.add(0, 10), std::out_of_range);
            CHECK_THROWS_AS(list.remove(10), std::out_of_range);

            SUBCASE("Bubble sort") {
        list.sort(bubble_sort);
        ss << list;
                CHECK(ss.str() == "[1, 2, 3, 4, 5]");
        ss.str("");

        list.sort(bubble_sort, compare_int_reverse);
        ss << list;
                CHECK(ss.str() == "[5, 4, 3, 2, 1]");
        ss.str("");
    }

            SUBCASE("Insertion sort") {
        list.sort(insertion_sort);
        ss << list;
                CHECK(ss.str() == "[1, 2, 3, 4, 5]");
        ss.str("");

        list.sort(insertion_sort, compare_int_reverse);
        ss << list;
                CHECK(ss.str() == "[5, 4, 3, 2, 1]");
        ss.str("");
    }

            SUBCASE("Merge sort") {
        list.sort(merge_sort);
        ss << list;
                CHECK(ss.str() == "[1, 2, 3, 4, 5]");
        ss.str("");

        list.sort(merge_sort, compare_int_reverse);
        ss << list;
                CHECK(ss.str() == "[5, 4, 3, 2, 1]");
        ss.str("");
    }

            SUBCASE("Quick sort") {
        list.sort(quick_sort);
        ss << list;
                CHECK(ss.str() == "[1, 2, 3, 4, 5]");
        ss.str("");

        list.sort(quick_sort, compare_int_reverse);
        ss << list;
                CHECK(ss.str() == "[5, 4, 3, 2, 1]");
        ss.str("");
    }

    list.clear();
    ss << list;
            CHECK(list.get_size() == 0);
            CHECK(ss.str() == "[]");

}

TEST_CASE ("[Integer] VectorList") {
    std::stringstream ss;

    VectorList<int> list;
            CHECK(list.get_size() == 0);

            CHECK_THROWS_AS(list.get(0), std::out_of_range);
            CHECK_THROWS_AS(list.get(10), std::out_of_range);
            CHECK_THROWS_AS(list.get(-1), std::out_of_range);

            CHECK_THROWS_AS(list.remove(0), std::out_of_range);
            CHECK_THROWS_AS(list.remove(10), std::out_of_range);
            CHECK_THROWS_AS(list.remove(-1), std::out_of_range);

            CHECK(list.find(0) == -1);

    list.add(4);
    list.add(2);
    list.add(1);
    ss << list;
            CHECK(ss.str() == "[4, 2, 1]");
    ss.str("");

    list.add(3, 1);
    ss << list;
            CHECK(ss.str() == "[4, 3, 2, 1]");
    ss.str("");

    list.add(5, -1); //when index < 0 -> index = last
    list.add(6, 2);
    list.add(7, 0);
    list.add(8, -5);
    ss << list;
            CHECK(ss.str() == "[7, 4, 3, 6, 2, 1, 5, 8]");
    ss.str("");

            CHECK(list.get_size() == 8);

    list.remove(0);
    list.remove(-1);
    list.remove(2);
    ss << list;
            CHECK(ss.str() == "[4, 3, 2, 1, 5]");
    ss.str("");

            CHECK(list.get_size() == 5);

            CHECK(list.get(0) == 4);
            CHECK(list.get(2) == 2);
            CHECK(list.get(-1) == 5);
            CHECK_THROWS_AS(list.get(10), std::out_of_range);

            CHECK(list.find(4) == 0);
            CHECK(list.find(2) == 2);
            CHECK(list.find(5) == 4);
            CHECK(list.find(8) == -1);

            CHECK_THROWS_AS(list.add(0, 10), std::out_of_range);
            CHECK_THROWS_AS(list.remove(10), std::out_of_range);

            SUBCASE("Bubble sort") {
        list.sort(bubble_sort);
        ss << list;
                CHECK(ss.str() == "[1, 2, 3, 4, 5]");
        ss.str("");

        list.sort(bubble_sort, compare_int_reverse);
        ss << list;
                CHECK(ss.str() == "[5, 4, 3, 2, 1]");
        ss.str("");
    }

            SUBCASE("Insertion sort") {
        list.sort(insertion_sort);
        ss << list;
                CHECK(ss.str() == "[1, 2, 3, 4, 5]");
        ss.str("");

        list.sort(insertion_sort, compare_int_reverse);
        ss << list;
                CHECK(ss.str() == "[5, 4, 3, 2, 1]");
        ss.str("");
    }

            SUBCASE("Merge sort") {
        list.sort(merge_sort);
        ss << list;
                CHECK(ss.str() == "[1, 2, 3, 4, 5]");
        ss.str("");

        list.sort(merge_sort, compare_int_reverse);
        ss << list;
                CHECK(ss.str() == "[5, 4, 3, 2, 1]");
        ss.str("");
    }

            SUBCASE("Quick sort") {
        list.sort(quick_sort);
        ss << list;
                CHECK(ss.str() == "[1, 2, 3, 4, 5]");
        ss.str("");

        list.sort(quick_sort, compare_int_reverse);
        ss << list;
                CHECK(ss.str() == "[5, 4, 3, 2, 1]");
        ss.str("");
    }

    list.clear();
    ss << list;
            CHECK(list.get_size() == 0);
            CHECK(ss.str() == "[]");
    ss.str("");

}

TEST_CASE ("[Double] ArrayList") {
    std::stringstream ss;

    ArrayList<double> list;
            CHECK(list.get_size() == 0);

            CHECK_THROWS_AS(list.get(0), std::out_of_range);
            CHECK_THROWS_AS(list.get(10), std::out_of_range);
            CHECK_THROWS_AS(list.get(-1), std::out_of_range);

            CHECK_THROWS_AS(list.remove(0), std::out_of_range);
            CHECK_THROWS_AS(list.remove(10), std::out_of_range);
            CHECK_THROWS_AS(list.remove(-1), std::out_of_range);

            CHECK(list.find(0) == -1);

    list.add(4.4);
    list.add(2.2);
    list.add(1.1);
    ss << list;
            CHECK(ss.str() == "[4.4, 2.2, 1.1]");
    ss.str("");

    list.add(3.3, 1);
    ss << list;
            CHECK(ss.str() == "[4.4, 3.3, 2.2, 1.1]");
    ss.str("");

    list.add(5.5, -1); //when index < 0 -> index = last
    list.add(6.6, 2);
    list.add(7.7, 0);
    list.add(8.8, -5);
    ss << list;
            CHECK(ss.str() == "[7.7, 4.4, 3.3, 6.6, 2.2, 1.1, 5.5, 8.8]");
    ss.str("");

            CHECK(list.get_size() == 8);

    list.remove(0);
    list.remove(-1);
    list.remove(2);
    ss << list;
            CHECK(ss.str() == "[4.4, 3.3, 2.2, 1.1, 5.5]");
    ss.str("");

            CHECK(list.get_size() == 5);

            CHECK(list.get(0) == 4.4);
            CHECK(list.get(2) == 2.2);
            CHECK(list.get(-1) == 5.5);
            CHECK_THROWS_AS(list.get(10), std::out_of_range);

            CHECK(list.find(4.4) == 0);
            CHECK(list.find(2.2) == 2);
            CHECK(list.find(5.5) == 4);
            CHECK(list.find(8.8) == -1);

            CHECK_THROWS_AS(list.add(0, 10), std::out_of_range);
            CHECK_THROWS_AS(list.remove(10), std::out_of_range);

            SUBCASE("Bubble sort") {
        list.sort(bubble_sort);
        ss << list;
                CHECK(ss.str() == "[1.1, 2.2, 3.3, 4.4, 5.5]");
        ss.str("");

        list.sort(bubble_sort, compare_double_reverse);
        ss << list;
                CHECK(ss.str() == "[5.5, 4.4, 3.3, 2.2, 1.1]");
        ss.str("");
    }

            SUBCASE("Insertion sort") {
        list.sort(insertion_sort);
        ss << list;
                CHECK(ss.str() == "[1.1, 2.2, 3.3, 4.4, 5.5]");
        ss.str("");

        list.sort(insertion_sort, compare_double_reverse);
        ss << list;
                CHECK(ss.str() == "[5.5, 4.4, 3.3, 2.2, 1.1]");
        ss.str("");
    }

            SUBCASE("Merge sort") {
        list.sort(merge_sort);
        ss << list;
                CHECK(ss.str() == "[1.1, 2.2, 3.3, 4.4, 5.5]");
        ss.str("");

        list.sort(merge_sort, compare_double_reverse);
        ss << list;
                CHECK(ss.str() == "[5.5, 4.4, 3.3, 2.2, 1.1]");
        ss.str("");
    }

            SUBCASE("Quick sort") {
        list.sort(quick_sort);
        ss << list;
                CHECK(ss.str() == "[1.1, 2.2, 3.3, 4.4, 5.5]");
        ss.str("");

        list.sort(quick_sort, compare_double_reverse);
        ss << list;
                CHECK(ss.str() == "[5.5, 4.4, 3.3, 2.2, 1.1]");
        ss.str("");
    }

    list.clear();
    ss << list;
            CHECK(list.get_size() == 0);
            CHECK(ss.str() == "[]");
}

TEST_CASE ("[Double] LinkedList") {
    std::stringstream ss;

    LinkedList<double> list;
            CHECK(list.get_size() == 0);

            CHECK_THROWS_AS(list.get(0), std::out_of_range);
            CHECK_THROWS_AS(list.get(10), std::out_of_range);
            CHECK_THROWS_AS(list.get(-1), std::out_of_range);

            CHECK_THROWS_AS(list.remove(0), std::out_of_range);
            CHECK_THROWS_AS(list.remove(10), std::out_of_range);
            CHECK_THROWS_AS(list.remove(-1), std::out_of_range);

            CHECK(list.find(0) == -1);

    list.add(4.4);
    list.add(2.2);
    list.add(1.1);
    ss << list;
            CHECK(ss.str() == "[4.4, 2.2, 1.1]");
    ss.str("");

    list.add(3.3, 1);
    ss << list;
            CHECK(ss.str() == "[4.4, 3.3, 2.2, 1.1]");
    ss.str("");

    list.add(5.5, -1); //when index < 0 -> index = last
    list.add(6.6, 2);
    list.add(7.7, 0);
    list.add(8.8, -5);
    ss << list;
            CHECK(ss.str() == "[7.7, 4.4, 3.3, 6.6, 2.2, 1.1, 5.5, 8.8]");
    ss.str("");

            CHECK(list.get_size() == 8);

    list.remove(0);
    list.remove(-1);
    list.remove(2);
    ss << list;
            CHECK(ss.str() == "[4.4, 3.3, 2.2, 1.1, 5.5]");
    ss.str("");

            CHECK(list.get_size() == 5);

            CHECK(list.get(0) == 4.4);
            CHECK(list.get(2) == 2.2);
            CHECK(list.get(-1) == 5.5);
            CHECK_THROWS_AS(list.get(10), std::out_of_range);

            CHECK(list.find(4.4) == 0);
            CHECK(list.find(2.2) == 2);
            CHECK(list.find(5.5) == 4);
            CHECK(list.find(8.8) == -1);

            CHECK_THROWS_AS(list.add(0, 10), std::out_of_range);
            CHECK_THROWS_AS(list.remove(10), std::out_of_range);

            SUBCASE("Bubble sort") {
        list.sort(bubble_sort);
        ss << list;
                CHECK(ss.str() == "[1.1, 2.2, 3.3, 4.4, 5.5]");
        ss.str("");

        list.sort(bubble_sort, compare_double_reverse);
        ss << list;
                CHECK(ss.str() == "[5.5, 4.4, 3.3, 2.2, 1.1]");
        ss.str("");
    }

            SUBCASE("Insertion sort") {
        list.sort(insertion_sort);
        ss << list;
                CHECK(ss.str() == "[1.1, 2.2, 3.3, 4.4, 5.5]");
        ss.str("");

        list.sort(insertion_sort, compare_double_reverse);
        ss << list;
                CHECK(ss.str() == "[5.5, 4.4, 3.3, 2.2, 1.1]");
        ss.str("");
    }

            SUBCASE("Merge sort") {
        list.sort(merge_sort);
        ss << list;
                CHECK(ss.str() == "[1.1, 2.2, 3.3, 4.4, 5.5]");
        ss.str("");

        list.sort(merge_sort, compare_double_reverse);
        ss << list;
                CHECK(ss.str() == "[5.5, 4.4, 3.3, 2.2, 1.1]");
        ss.str("");
    }

            SUBCASE("Quick sort") {
        list.sort(quick_sort);
        ss << list;
                CHECK(ss.str() == "[1.1, 2.2, 3.3, 4.4, 5.5]");
        ss.str("");

        list.sort(quick_sort, compare_double_reverse);
        ss << list;
                CHECK(ss.str() == "[5.5, 4.4, 3.3, 2.2, 1.1]");
        ss.str("");
    }

    list.clear();
    ss << list;
            CHECK(list.get_size() == 0);
            CHECK(ss.str() == "[]");
}

TEST_CASE ("[Double] VectorList") {
    std::stringstream ss;

    VectorList<double> list;
            CHECK(list.get_size() == 0);

            CHECK_THROWS_AS(list.get(0), std::out_of_range);
            CHECK_THROWS_AS(list.get(10), std::out_of_range);
            CHECK_THROWS_AS(list.get(-1), std::out_of_range);

            CHECK_THROWS_AS(list.remove(0), std::out_of_range);
            CHECK_THROWS_AS(list.remove(10), std::out_of_range);
            CHECK_THROWS_AS(list.remove(-1), std::out_of_range);

            CHECK(list.find(0) == -1);

    list.add(4.4);
    list.add(2.2);
    list.add(1.1);
    ss << list;
            CHECK(ss.str() == "[4.4, 2.2, 1.1]");
    ss.str("");

    list.add(3.3, 1);
    ss << list;
            CHECK(ss.str() == "[4.4, 3.3, 2.2, 1.1]");
    ss.str("");

    list.add(5.5, -1); //when index < 0 -> index = last
    list.add(6.6, 2);
    list.add(7.7, 0);
    list.add(8.8, -5);
    ss << list;
            CHECK(ss.str() == "[7.7, 4.4, 3.3, 6.6, 2.2, 1.1, 5.5, 8.8]");
    ss.str("");

            CHECK(list.get_size() == 8);

    list.remove(0);
    list.remove(-1);
    list.remove(2);
    ss << list;
            CHECK(ss.str() == "[4.4, 3.3, 2.2, 1.1, 5.5]");
    ss.str("");

            CHECK(list.get_size() == 5);

            CHECK(list.get(0) == 4.4);
            CHECK(list.get(2) == 2.2);
            CHECK(list.get(-1) == 5.5);
            CHECK_THROWS_AS(list.get(10), std::out_of_range);

            CHECK(list.find(4.4) == 0);
            CHECK(list.find(2.2) == 2);
            CHECK(list.find(5.5) == 4);
            CHECK(list.find(8.8) == -1);

            CHECK_THROWS_AS(list.add(0, 10), std::out_of_range);
            CHECK_THROWS_AS(list.remove(10), std::out_of_range);

            SUBCASE("Bubble sort") {
        list.sort(bubble_sort);
        ss << list;
                CHECK(ss.str() == "[1.1, 2.2, 3.3, 4.4, 5.5]");
        ss.str("");

        list.sort(bubble_sort, compare_double_reverse);
        ss << list;
                CHECK(ss.str() == "[5.5, 4.4, 3.3, 2.2, 1.1]");
        ss.str("");
    }

            SUBCASE("Insertion sort") {
        list.sort(insertion_sort);
        ss << list;
                CHECK(ss.str() == "[1.1, 2.2, 3.3, 4.4, 5.5]");
        ss.str("");

        list.sort(insertion_sort, compare_double_reverse);
        ss << list;
                CHECK(ss.str() == "[5.5, 4.4, 3.3, 2.2, 1.1]");
        ss.str("");
    }

            SUBCASE("Merge sort") {
        list.sort(merge_sort);
        ss << list;
                CHECK(ss.str() == "[1.1, 2.2, 3.3, 4.4, 5.5]");
        ss.str("");

        list.sort(merge_sort, compare_double_reverse);
        ss << list;
                CHECK(ss.str() == "[5.5, 4.4, 3.3, 2.2, 1.1]");
        ss.str("");
    }

            SUBCASE("Quick sort") {
        list.sort(quick_sort);
        ss << list;
                CHECK(ss.str() == "[1.1, 2.2, 3.3, 4.4, 5.5]");
        ss.str("");

        list.sort(quick_sort, compare_double_reverse);
        ss << list;
                CHECK(ss.str() == "[5.5, 4.4, 3.3, 2.2, 1.1]");
        ss.str("");
    }

    list.clear();
    ss << list;
            CHECK(list.get_size() == 0);
            CHECK(ss.str() == "[]");
}

TEST_CASE ("[String] ArrayList") {
    std::stringstream ss;

    ArrayList<std::string> list;
            CHECK(list.get_size() == 0);

            CHECK_THROWS_AS(list.get(0), std::out_of_range);
            CHECK_THROWS_AS(list.get(10), std::out_of_range);
            CHECK_THROWS_AS(list.get(-1), std::out_of_range);

            CHECK_THROWS_AS(list.remove(0), std::out_of_range);
            CHECK_THROWS_AS(list.remove(10), std::out_of_range);
            CHECK_THROWS_AS(list.remove(-1), std::out_of_range);

            CHECK(list.find("k") == -1);

    list.add("d");
    list.add("b");
    list.add("a");
    ss << list;
            CHECK(ss.str() == "[d, b, a]");
    ss.str("");

    list.add("c", 1);
    ss << list;
            CHECK(ss.str() == "[d, c, b, a]");
    ss.str("");

    list.add("e", -1); //when index < 0 -> index = last
    list.add("f", 2);
    list.add("g", 0);
    list.add("h", -5);
    ss << list;
            CHECK(ss.str() == "[g, d, c, f, b, a, e, h]");
    ss.str("");

            CHECK(list.get_size() == 8);

    list.remove(0);
    list.remove(-1);
    list.remove(2);
    ss << list;
            CHECK(ss.str() == "[d, c, b, a, e]");
    ss.str("");

            CHECK(list.get_size() == 5);

            CHECK(list.get(0) == "d");
            CHECK(list.get(2) == "b");
            CHECK(list.get(-1) == "e");
            CHECK_THROWS_AS(list.get(10), std::out_of_range);

            CHECK(list.find("d") == 0);
            CHECK(list.find("b") == 2);
            CHECK(list.find("e") == 4);
            CHECK(list.find("h") == -1);

            CHECK_THROWS_AS(list.add("j", 10), std::out_of_range);
            CHECK_THROWS_AS(list.remove(10), std::out_of_range);

            SUBCASE("Bubble sort") {
        list.sort(bubble_sort);
        ss << list;
                CHECK(ss.str() == "[a, b, c, d, e]");
        ss.str("");

        list.sort(bubble_sort, compare_string_reverse);
        ss << list;
                CHECK(ss.str() == "[e, d, c, b, a]");
        ss.str("");
    }

            SUBCASE("Insertion sort") {
        list.sort(insertion_sort);
        ss << list;
                CHECK(ss.str() == "[a, b, c, d, e]");
        ss.str("");

        list.sort(insertion_sort, compare_string_reverse);
        ss << list;
                CHECK(ss.str() == "[e, d, c, b, a]");
        ss.str("");
    }

            SUBCASE("Merge sort") {
        list.sort(merge_sort);
        ss << list;
                CHECK(ss.str() == "[a, b, c, d, e]");
        ss.str("");

        list.sort(merge_sort, compare_string_reverse);
        ss << list;
                CHECK(ss.str() == "[e, d, c, b, a]");
        ss.str("");
    }

            SUBCASE("Quick sort") {
        list.sort(quick_sort);
        ss << list;
                CHECK(ss.str() == "[a, b, c, d, e]");
        ss.str("");

        list.sort(quick_sort, compare_string_reverse);
        ss << list;
                CHECK(ss.str() == "[e, d, c, b, a]");
        ss.str("");
    }

    list.clear();
    ss << list;
            CHECK(list.get_size() == 0);
            CHECK(ss.str() == "[]");
}

TEST_CASE ("[String] LinkedList") {
    std::stringstream ss;

    LinkedList<std::string> list;
            CHECK(list.get_size() == 0);

            CHECK_THROWS_AS(list.get(0), std::out_of_range);
            CHECK_THROWS_AS(list.get(10), std::out_of_range);
            CHECK_THROWS_AS(list.get(-1), std::out_of_range);

            CHECK_THROWS_AS(list.remove(0), std::out_of_range);
            CHECK_THROWS_AS(list.remove(10), std::out_of_range);
            CHECK_THROWS_AS(list.remove(-1), std::out_of_range);

            CHECK(list.find("k") == -1);

    list.add("d");
    list.add("b");
    list.add("a");
    ss << list;
            CHECK(ss.str() == "[d, b, a]");
    ss.str("");

    list.add("c", 1);
    ss << list;
            CHECK(ss.str() == "[d, c, b, a]");
    ss.str("");

    list.add("e", -1); //when index < 0 -> index = last
    list.add("f", 2);
    list.add("g", 0);
    list.add("h", -5);
    ss << list;
            CHECK(ss.str() == "[g, d, c, f, b, a, e, h]");
    ss.str("");

            CHECK(list.get_size() == 8);

    list.remove(0);
    list.remove(-1);
    list.remove(2);
    ss << list;
            CHECK(ss.str() == "[d, c, b, a, e]");
    ss.str("");

            CHECK(list.get_size() == 5);

            CHECK(list.get(0) == "d");
            CHECK(list.get(2) == "b");
            CHECK(list.get(-1) == "e");
            CHECK_THROWS_AS(list.get(10), std::out_of_range);

            CHECK(list.find("d") == 0);
            CHECK(list.find("b") == 2);
            CHECK(list.find("e") == 4);
            CHECK(list.find("h") == -1);

            CHECK_THROWS_AS(list.add("j", 10), std::out_of_range);
            CHECK_THROWS_AS(list.remove(10), std::out_of_range);

            SUBCASE("Bubble sort") {
        list.sort(bubble_sort);
        ss << list;
                CHECK(ss.str() == "[a, b, c, d, e]");
        ss.str("");

        list.sort(bubble_sort, compare_string_reverse);
        ss << list;
                CHECK(ss.str() == "[e, d, c, b, a]");
        ss.str("");
    }

            SUBCASE("Insertion sort") {
        list.sort(insertion_sort);
        ss << list;
                CHECK(ss.str() == "[a, b, c, d, e]");
        ss.str("");

        list.sort(insertion_sort, compare_string_reverse);
        ss << list;
                CHECK(ss.str() == "[e, d, c, b, a]");
        ss.str("");
    }

            SUBCASE("Merge sort") {
        list.sort(merge_sort);
        ss << list;
                CHECK(ss.str() == "[a, b, c, d, e]");
        ss.str("");

        list.sort(merge_sort, compare_string_reverse);
        ss << list;
                CHECK(ss.str() == "[e, d, c, b, a]");
        ss.str("");
    }

            SUBCASE("Quick sort") {
        list.sort(quick_sort);
        ss << list;
                CHECK(ss.str() == "[a, b, c, d, e]");
        ss.str("");

        list.sort(quick_sort, compare_string_reverse);
        ss << list;
                CHECK(ss.str() == "[e, d, c, b, a]");
        ss.str("");
    }

    list.clear();
    ss << list;
            CHECK(list.get_size() == 0);
            CHECK(ss.str() == "[]");
}

TEST_CASE ("[String] VectorList") {
    std::stringstream ss;

    VectorList<std::string> list;
            CHECK(list.get_size() == 0);

            CHECK_THROWS_AS(list.get(0), std::out_of_range);
            CHECK_THROWS_AS(list.get(10), std::out_of_range);
            CHECK_THROWS_AS(list.get(-1), std::out_of_range);

            CHECK_THROWS_AS(list.remove(0), std::out_of_range);
            CHECK_THROWS_AS(list.remove(10), std::out_of_range);
            CHECK_THROWS_AS(list.remove(-1), std::out_of_range);

            CHECK(list.find("k") == -1);

    list.add("d");
    list.add("b");
    list.add("a");
    ss << list;
            CHECK(ss.str() == "[d, b, a]");
    ss.str("");

    list.add("c", 1);
    ss << list;
            CHECK(ss.str() == "[d, c, b, a]");
    ss.str("");

    list.add("e", -1); //when index < 0 -> index = last
    list.add("f", 2);
    list.add("g", 0);
    list.add("h", -5);
    ss << list;
            CHECK(ss.str() == "[g, d, c, f, b, a, e, h]");
    ss.str("");

            CHECK(list.get_size() == 8);

    list.remove(0);
    list.remove(-1);
    list.remove(2);
    ss << list;
            CHECK(ss.str() == "[d, c, b, a, e]");
    ss.str("");

            CHECK(list.get_size() == 5);

            CHECK(list.get(0) == "d");
            CHECK(list.get(2) == "b");
            CHECK(list.get(-1) == "e");
            CHECK_THROWS_AS(list.get(10), std::out_of_range);

            CHECK(list.find("d") == 0);
            CHECK(list.find("b") == 2);
            CHECK(list.find("e") == 4);
            CHECK(list.find("h") == -1);

            CHECK_THROWS_AS(list.add("j", 10), std::out_of_range);
            CHECK_THROWS_AS(list.remove(10), std::out_of_range);

            SUBCASE("Bubble sort") {
        list.sort(bubble_sort);
        ss << list;
                CHECK(ss.str() == "[a, b, c, d, e]");
        ss.str("");

        list.sort(bubble_sort, compare_string_reverse);
        ss << list;
                CHECK(ss.str() == "[e, d, c, b, a]");
        ss.str("");
    }

            SUBCASE("Insertion sort") {
        list.sort(insertion_sort);
        ss << list;
                CHECK(ss.str() == "[a, b, c, d, e]");
        ss.str("");

        list.sort(insertion_sort, compare_string_reverse);
        ss << list;
                CHECK(ss.str() == "[e, d, c, b, a]");
        ss.str("");
    }

            SUBCASE("Merge sort") {
        list.sort(merge_sort);
        ss << list;
                CHECK(ss.str() == "[a, b, c, d, e]");
        ss.str("");

        list.sort(merge_sort, compare_string_reverse);
        ss << list;
                CHECK(ss.str() == "[e, d, c, b, a]");
        ss.str("");
    }

            SUBCASE("Quick sort") {
        list.sort(quick_sort);
        ss << list;
                CHECK(ss.str() == "[a, b, c, d, e]");
        ss.str("");

        list.sort(quick_sort, compare_string_reverse);
        ss << list;
                CHECK(ss.str() == "[e, d, c, b, a]");
        ss.str("");
    }

    list.clear();
    ss << list;
            CHECK(list.get_size() == 0);
            CHECK(ss.str() == "[]");
}

//TEST_CASE ("[Vector] ArrayList") {
//    std::stringstream ss;
//
//    ArrayList<std::vector<int>> list;
//            CHECK(list.get_size() == 0);
//
//            CHECK_THROWS_AS(list.get(0), std::out_of_range);
//            CHECK_THROWS_AS(list.get(10), std::out_of_range);
//            CHECK_THROWS_AS(list.get(-1), std::out_of_range);
//
//            CHECK_THROWS_AS(list.remove(0), std::out_of_range);
//            CHECK_THROWS_AS(list.remove(10), std::out_of_range);
//            CHECK_THROWS_AS(list.remove(-1), std::out_of_range);
//
//            CHECK(list.find({0}) == -1);
//
//    list.add({4, 4, 4, 4});
//    list.add({2, 2});
//    list.add({1});
//    ss << list;
//            CHECK(ss.str() == "[4, 2, 1]");
//    ss.str("");
//
//    list.add({3, 3, 3}, 1);
//    ss << list;
//            CHECK(ss.str() == "[4, 3, 2, 1]");
//    ss.str("");
//
//    list.add({5, 5, 5, 5, 5}, -1); //when index < 0 -> index = last
//    list.add({6, 6, 6, 6, 6, 6}, 2);
//    list.add({7, 7, 7, 7, 7, 7, 7}, 0);
//    list.add({8, 8, 8, 8, 8, 8, 8, 8}, -5);
//    ss << list;
//            CHECK(ss.str() == "[7, 4, 3, 6, 2, 1, 5, 8]");
//    ss.str("");
//
//            CHECK(list.get_size() == 8);
//
//    list.remove(0);
//    list.remove(-1);
//    list.remove(2);
//    ss << list;
//            CHECK(ss.str() == "[4, 3, 2, 1, 5]");
//    ss.str("");
//
//            CHECK(list.get_size() == 5);
//
//            CHECK(list.get(0) == 4);
//            CHECK(list.get(2) == 2);
//            CHECK(list.get(-1) == 5);
//            CHECK_THROWS_AS(list.get(10), std::out_of_range);
//
//            CHECK(list.find({4, 4, 4, 4}) == 0);
//            CHECK(list.find({2, 2}) == 2);
//            CHECK(list.find({5, 5, 5, 5, 5}) == 4);
//            CHECK(list.find({8, 8, 8, 8, 8, 8, 8, 8}) == -1);
//
//            CHECK_THROWS_AS(list.add({0}, 10), std::out_of_range);
//            CHECK_THROWS_AS(list.remove(10), std::out_of_range);
//
//            SUBCASE("Bubble sort") {
//        list.sort(bubble_sort);
//        ss << list;
//                CHECK(ss.str() == "[1, 2, 3, 4, 5]");
//        ss.str("");
//
//        list.sort(bubble_sort, compare_vector_reverse);
//        ss << list;
//                CHECK(ss.str() == "[5, 4, 3, 2, 1]");
//        ss.str("");
//    }
//
//            SUBCASE("Insertion sort") {
//        list.sort(insertion_sort);
//        ss << list;
//                CHECK(ss.str() == "[1, 2, 3, 4, 5]");
//        ss.str("");
//
//        list.sort(insertion_sort, compare_vector_reverse);
//        ss << list;
//                CHECK(ss.str() == "[5, 4, 3, 2, 1]");
//        ss.str("");
//    }
//
//            SUBCASE("Merge sort") {
//        list.sort(merge_sort);
//        ss << list;
//                CHECK(ss.str() == "[1, 2, 3, 4, 5]");
//        ss.str("");
//
//        list.sort(merge_sort, compare_vector_reverse);
//        ss << list;
//                CHECK(ss.str() == "[5, 4, 3, 2, 1]");
//        ss.str("");
//    }
//
//            SUBCASE("Quick sort") {
//        list.sort(quick_sort);
//        ss << list;
//                CHECK(ss.str() == "[1, 2, 3, 4, 5]");
//        ss.str("");
//
//        list.sort(quick_sort, compare_vector_reverse);
//        ss << list;
//                CHECK(ss.str() == "[5, 4, 3, 2, 1]");
//        ss.str("");
//    }
//
//    list.clear();
//    ss << list;
//            CHECK(list.get_size() == 0);
//            CHECK(ss.str() == "[]");
//}


