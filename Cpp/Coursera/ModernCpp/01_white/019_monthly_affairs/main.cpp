#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    const vector<size_t> monthly_days = { 31, 28, 31, 30, 31, 30, 31, 31, 30,
        31, 30, 31 };
    size_t current_month = 0;
    vector<vector<string>> affairs(monthly_days[current_month]);

    size_t n = 0;
    cin >> n;
    for (size_t i = 0; i < n; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "ADD" || cmd == "A") {
            int number = 0;
            string name;
            cin >> number >> name;
            affairs[number - 1].push_back(name);
        } else if (cmd == "DUMP" || cmd == "D") {
            int number = 0;
            cin >> number;
            cout << affairs[number - 1].size();
            for (auto &name : affairs[number - 1]) {
                cout << ' ' << name;
            }
            cout << endl;
        } else if (cmd == "NEXT" || cmd == "N") {
            current_month = (current_month + 1) % monthly_days.size();
            size_t days = monthly_days[current_month];
            if (days <= affairs.size()) {
                for (size_t d = days; d < affairs.size(); ++d) {
                    affairs[days - 1].insert(end(affairs[days - 1]),
                            begin(affairs[d]), end(affairs[d]));
                    affairs[d].clear();
                }
            }
            affairs.resize(days);
        }
    }
    return 0;
}

/*
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// глобальные (доступные во всей программе) константы
// часто принято называть ЗАГЛАВНЫМИ_БУКВАМИ
const vector<int> MONTH_LENGTHS =
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int MONTH_COUNT = MONTH_LENGTHS.size();

int main() {
    int q;
    cin >> q;

    // номер текущего месяца (от 0 до 11)
    int month = 0;

    // внешний вектор должен иметь длину, равную количеству дней в первом месяце;
    // все внутренние векторы по умолчанию пусты, потому что дел изначально нет
    vector<vector<string>> days_concerns(MONTH_LENGTHS[month]);

    for (int i = 0; i < q; ++i) {
        string operation_code;
        cin >> operation_code;

        if (operation_code == "ADD") {

            int day;
            string concern;
            cin >> day >> concern;
            --day;  // элементы вектора нумеруются с нуля
            days_concerns[day].push_back(concern);

        } else if (operation_code == "NEXT") {

            // перед переходом к следующему месяцу запомним длину предыдущего
            // обьявляем эту переменную константной, потому что менять её не планируем
            const int old_month_length = MONTH_LENGTHS[month];

            // номер месяца должен увеличиться на 1, но после декабря идёт январь:
            // например, (5 + 1) % 12 = 6, но (11 + 1) % 12 = 0
            month = (month + 1) % MONTH_COUNT;

            const int new_month_length = MONTH_LENGTHS[month];

            // если новый месяц больше предыдущего, достаточно сделать resize;
            // иначе перед resize надо переместить дела с «лишних» последних дней
            if (new_month_length < old_month_length) {

                // далее понадобится добавлять новые дела в последний день нового месяца
                // чтобы не писать несколько раз days_concerns[new_month_length - 1],
                // создадим ссылку с более коротким названием для этого вектора
                vector<string>& last_day_concerns = days_concerns[new_month_length - 1];

                // перебираем все «лишние» дни в конце месяца
                for (int day = new_month_length; day < old_month_length; ++day) {
                    // копируем вектор days_concerns[day]
                    // в конец вектора last_day_concerns
                    last_day_concerns.insert(
                        end(last_day_concerns),
                        begin(days_concerns[day]), end(days_concerns[day]));
                }
            }
            days_concerns.resize(new_month_length);

        } else if (operation_code == "DUMP") {

            int day;
            cin >> day;
            --day;

            // выводим список дел в конкретный день в нужном формате
            cout << days_concerns[day].size() << " ";
            for (const string& concern : days_concerns[day]) {
                cout << concern << " ";
            }
            cout << endl;

        }
    }

    return 0;
}
*/
