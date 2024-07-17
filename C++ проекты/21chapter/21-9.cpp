#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string_view>

struct StudentGrade
{
    std::string name{};
    char grade{};
};

class GradeMap
{
private:
    std::vector<StudentGrade> m_map{};

public:
    GradeMap(): 
        m_map{}
    {}

    char& operator[](std::string_view name);
};

char& GradeMap::operator[](std::string_view name) 
{
    auto found { std::find_if(m_map.begin(), m_map.end(), 
                [&name](const auto& student)
                {
                    return student.name == name;
                }) };

    if (found != m_map.end() )
    {
        return found -> grade;
    }
    else
    {
        m_map.emplace_back(std::string{name});
        return m_map.back().grade;
    }
}

int main()
{
	GradeMap grades{};

	char& gradeJoe{ grades["Joe"] }; // does an emplace_back
	gradeJoe = 'A';

	char& gradeFrank{ grades["Frank"] }; // does a emplace_back
	gradeFrank = 'B';

	std::cout << "Joe has a grade of " << gradeJoe << '\n';
	std::cout << "Frank has a grade of " << gradeFrank << '\n';

	return 0;
}