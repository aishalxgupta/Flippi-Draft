#include <iostream>
#include <vector>
#include <string>

class Student {
private:
    std::string name;
    std::string email;
    std::vector<std::string> courses;

public:
    Student(const std::string& name, const std::string& email) : name(name), email(email), courses() {}

    /**
     * Enrolls a student in a course.
     *
     * @param courseName The name of the course to enroll in.
     *
     * @throws None
     */
    void enrollCourse(const std::string& courseName) {
        courses.push_back(courseName);
    }

    void dropCourse(const std::string& courseName) {
        courses.erase(std::remove(courses.begin(), courses.end(), courseName), courses.end());
    }

    const std::vector<std::string>& getEnrolledCourses() const {
        return courses;
    }

    const std::string& getName() const {
        return name;
    }

    const std::string& getEmail() const {
        return email;
    }
};

class Course {
private:
    std::string name;
    int capacity;
    std::vector<Student> students;

public:
    Course(const std::string& name, int capacity) : name(name), capacity(capacity), students() {}

    void enrollStudent(Student& student) {
        if (students.size() < capacity) {
            students.push_back(student);
            student.enrollCourse(name);
            std::cout << student.getName() << " enrolled in " << name << std::endl;
        } else {
            std::cout << "Course is full. Cannot enroll " << student.getName() << std::endl;
        }
    }

    void dropStudent(Student& student) {
        students.erase(std::remove(students.begin(), students.end(), student), students.end());
        student.dropCourse(name);
        std::cout << student.getName() << " dropped from " << name << std::endl;
    }

    const std::vector<Student>& getEnrolledStudents() const {
        return students;
    }

    const std::string& getName() const {
        return name;
    }

    int getCapacity() const {
        return capacity;
    }
};

class CourseRegistrationSystem {
private:
    std::vector<Course> courses;

public:
    void addCourse(const Course& course) {
        courses.push_back(course);
    }

    void enrollStudent(Student& student, const Course& course) {
        for (const auto& c : courses) {
            if (c.getName() == course.getName()) {
                c.enrollStudent(student);
                break;
            }
        }
    }

    void dropStudent(Student& student, const Course& course) {
        for (const auto& c : courses) {
            if (c.getName() == course.getName()) {
                c.dropStudent(student);
                break;
            }
        }
    }

    const std::vector<Course>& getCourses() const {
        return courses;
    }
};

int main() {
    CourseRegistrationSystem system;

    // Create courses
    Course course1("Java Programming", 30);
    Course course2("Data Structures", 20);

    // Add courses to the system
    system.addCourse(course1);
    system.addCourse(course2);

    // Create students
    Student student1("John Doe", "john@example.com");
    Student student2("Jane Smith", "jane@example.com");

    // Enroll students in courses
    system.enrollStudent(student1, course1);
    system.enrollStudent(student2, course2);

    // Drop students from courses
    system.dropStudent(student1, course1);
    system.dropStudent(student2, course2);

    return 0;
}