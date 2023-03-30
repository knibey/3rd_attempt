#include <iostream>
#include <string>
#include <vector>

struct StudentGrades {
	std::string name;
	char grade;
};

class GradeMap {
private:
	std::vector<StudentGrades> m_map;

public:
	GradeMap() {}

	char& operator[] (const std::string& name) {

		for ( auto &student : m_map) {
			if (student.name == name) {
				return student.grade;
			}
		}

		StudentGrades temp{ name, ' '};
		m_map.push_back(temp);

		return m_map.back().grade;
	}
};

int mainlesson146()
{
	GradeMap grades;
	grades["John"] = 'A';
	grades["Martin"] = 'B';
	std::cout << "John has a grade of " << grades["John"] << '\n';
	std::cout << "Martin has a grade of " << grades["Martin"] << '\n';

	return 0;
}