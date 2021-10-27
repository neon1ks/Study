#include <iostream>
#include <cmath>
#include <vector>
#include <random>

using namespace std;

bool check_step(long floors, long number, long entrance, long floor, long step)
{
    // cout << "Check: ";
    // cout << "floors=" << floors;
    // cout << ", number= " << number;
    // cout << ", entrance=" << entrance;
    // cout << ", floor = " << floor;
    // cout << ", step = " << step << endl;

    bool status = true;
    if (step <= 0) {
        status = false;
    }
    if (status && (number > ((entrance - 1) * floors + floor) * step)) {
        status = false;
    }
    if (status && (number <= ((entrance - 1) * floors + floor - 1) * step)) {
        status = false;
    }
    return status;
}

bool valid(long floors, long number, long entrance, long floor)
{
    if (number < floor) {
        return false;
    }
    if (floors < floor) {
        return false;
    }
    if (number < entrance) {
        return false;
    }
    if (number < entrance * floor) {
        return false;
    }
    if (number < 0) {
        return false;
    }
    if (entrance < 0) {
        return false;
    }
    if (floor < 0) {
        return false;
    }
    return true;
}
long choose(long one, long two)
{
    if (one <= 0 && two > 0) {
        return two;
    }
    if (one > 0 && two <= 0) {
        return one;
    }
    if (one <= 0 && two <= 0) {
        return -1;
    }
    if (one == two) {
        return one;
    }
    return 0;
}

long calc_step_max(long floors, long number, long floor, long entrance)
{
    return static_cast<long>(trunc(
            static_cast<double>(number - 1)
            / static_cast<double>(floor - 1 + (entrance - 1) * floors)));
}

long calc_step_min(long floors, long number, long floor, long entrance)
{
    return static_cast<long>(
            ceil(static_cast<double>(number)
                    / static_cast<double>(floor + (entrance - 1) * floors)));
}

long calc_entrance(long number, long step, long floors)
{
    return (number - 1) / (step * floors) + 1;
}

long calc_floor(long number, long step, long floors, long entrance)
{
    return (number - 1 - (entrance - 1) * floors * step) / step + 1;
}

void calc(const vector<long> &in, vector<long> &out)
{
    if (in.size() < 5) {
        return;
    }
    long number1 = in[0];    // номер квартиры
    long floors = in[1];     // Количество этажей
    long number2 = in[2];    // номер квартиры 2
    long entrance2 = in[3];  // номер подъезда
    long floor2 = in[4];     // номер этажа

    //std::cin >> number1 >> floors >> number2 >> entrance2 >> floor2;

    long entrance1 = 0;
    long floor1 = 0;

    // if (!valid(floors, number2, entrance2, floor2)) {
    //     entrance1 = -1;
    //     floor1 = -1;
    // } else
    if (number1 == number2) {
        entrance1 = entrance2;
        floor1 = floor2;
    } else if (floor2 > 1 || entrance2 > 1) {

        long step_max = static_cast<long>(trunc(
                static_cast<double>(number2 - 1)
                / static_cast<double>(floor2 - 1 + (entrance2 - 1) * floors)));

        long step_min = static_cast<long>(ceil(
                static_cast<double>(number2)
                / static_cast<double>(floor2 + (entrance2 - 1) * floors)));

        // cout << "step_min = " << step_min << endl;
        // cout << "step_max = " << step_max << endl;

        long entrance1_one = 0;
        long floor1_one = 0;

        if (check_step(floors, number2, entrance2, floor2, step_max)) {
            entrance1_one = calc_entrance(number1, step_max, floors);
            floor1_one = calc_floor(number1, step_max, floors, entrance1_one);
            if (!check_step(
                        floors, number1, entrance1_one, floor1_one, step_max)) {
                entrance1_one = -1;
                floor1_one = -1;
            }
        } else {
            entrance1_one = -1;
            floor1_one = -1;
        }

        long entrance1_two = 0;
        long floor1_two = 0;

        if (check_step(floors, number2, entrance2, floor2, step_min)) {
            entrance1_two = calc_entrance(number1, step_min, floors);
            floor1_two = calc_floor(number1, step_min, floors, entrance1_two);
            if (!check_step(
                        floors, number1, entrance1_two, floor1_two, step_min)) {
                entrance1_two = -1;
                floor1_two = -1;
            }
        } else {
            entrance1_two = -1;
            floor1_two = -1;
        }

        // cout << "entrance1_one = " << entrance1_one << endl;
        // cout << "floor1_one = " << floor1_one << endl;
        // cout << "entrance1_two = " << entrance1_two << endl;
        // cout << "floor1_two = " << floor1_two << endl;

        entrance1 = choose(entrance1_one, entrance1_two);
        floor1 = choose(floor1_one, floor1_two);
        if (!valid(floors, number1, entrance1, floor1)) {
            entrance1 = -1;
            floor1 = -1;
        }

    } else {
        if (number1 == 1 || number1 < number2) {
            //cout << 1 << ' ' << 1 << endl;
            entrance1 = 1;
            floor1 = 1;
        } else if (floors == 1 && number1 > 1) {
            //cout << 0 << ' ' << 1 << endl;
            entrance1 = 0;
            floor1 = 1;
        }
    }

    //cout << entrance1 << ' ' << floor1 << endl;
    out[0] = entrance1;
    out[1] = floor1;
}

void test1()
{
    long floors = 0;
    long number = 0;
    long floor = 0;
    long entrance = 0;
    long step_max = 0;
    long step_min = 0;

    cout << "Check 1: ";

    floors = 10;
    number = 4;
    floor = 2;
    entrance = 1;

    cout << "floors=" << floors;
    cout << ", number= " << number;
    cout << ", entrance=" << entrance;
    cout << ", floor = " << floor << endl;

    step_max = calc_step_max(floors, number, floor, entrance);
    step_min = calc_step_min(floors, number, floor, entrance);

    cout << "         step_max=" << step_max << ", ";
    cout << "step_min=" << step_min << endl << endl;

    cout << "Check 2: ";

    floors = 10;
    number = 5;
    floor = 2;
    entrance = 1;

    cout << "floors=" << floors;
    cout << ", number= " << number;
    cout << ", entrance=" << entrance;
    cout << ", floor = " << floor << endl;

    step_max = calc_step_max(floors, number, floor, entrance);
    step_min = calc_step_min(floors, number, floor, entrance);

    cout << "         step_max=" << step_max << ", ";
    cout << "step_min=" << step_min << endl << endl;

    cout << "Check 3: ";

    floors = 10;
    number = 6;
    floor = 2;
    entrance = 1;

    cout << "floors=" << floors;
    cout << ", number= " << number;
    cout << ", entrance=" << entrance;
    cout << ", floor = " << floor << endl;

    step_max = calc_step_max(floors, number, floor, entrance);
    step_min = calc_step_min(floors, number, floor, entrance);

    cout << "         step_max=" << step_max << ", ";
    cout << "step_min=" << step_min << endl << endl;

    cout << "Check 4: ";

    floors = 10;
    number = 12;
    floor = 3;
    entrance = 1;

    cout << "floors=" << floors;
    cout << ", number= " << number;
    cout << ", entrance=" << entrance;
    cout << ", floor = " << floor << endl;

    step_max = calc_step_max(floors, number, floor, entrance);
    step_min = calc_step_min(floors, number, floor, entrance);

    cout << "         step_max=" << step_max << ", ";
    cout << "step_min=" << step_min << endl << endl;
}

void test2()
{
    const size_t repeat = 10000;

    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> gen_namber1(1, 1000);
    std::uniform_int_distribution<int> gen_namber2(1, 1000);
    std::uniform_int_distribution<int> gen_floors(1, 20);
    std::uniform_int_distribution<int> gen_step(1, 20);

    vector<long> in(5);
    vector<long> out(2);

    for (int i = 0; i < repeat; ++i) {

        long number1 = gen_namber1(e1);
        long number2 = gen_namber2(e1);
        long floors = gen_floors(e1);
        long step = gen_step(e1);

        long entrance2 = (number2 - 1) / (step * floors) + 1;  // номер подъезда
        long floor2 =
                ((number2 - 1) % (step * floors)) / step + 1;  // номер этажа

        long entrance1 = (number1 - 1) / (step * floors) + 1;  // номер подъезда
        long floor1 =
                ((number1 - 1) % (step * floors)) / step + 1;  // номер этажа

        in[0] = number1;
        in[1] = floors;
        in[2] = number2;
        in[3] = entrance2;
        in[4] = floor2;

        calc(in, out);

        if (out[0] != entrance1 || out[1] != floor1) {
            cout << "Test: " << i << endl;
            cout << "floors=" << floors;
            cout << ", number1= " << number1;
            cout << ", number2= " << number2;
            cout << ", step=" << step << endl;

            cout << "entrance2=" << entrance2;
            cout << ", floor2= " << floor2;
            cout << ", entrance1= " << entrance1;
            cout << ", floor1=" << floor1 << endl;

            cout << "out[0] entrance1=" << out[0];
            cout << ", out[1] floor1= " << out[1] << endl << endl;
        }
    }
}

int main()
{
    test2();
    return 0;
}
