#include "comparison.h"

bool Compare(const Date& left, Comparison cmp, const Date& right) {
    switch(cmp) {
        case Comparison::Less:
            return left < right;
        case Comparison::LessOrEqual:
            return left <= right;
        case Comparison::Greater:
            return left > right;
        case Comparison::GreaterOrEqual:
            return left >= right;
        case Comparison::Equal:
            return left == right;
        case Comparison::NotEqual:
            return left != right;
    }

    return false;
}
