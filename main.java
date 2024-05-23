import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Student {
    private String name;
    private String email;
    private List<String> courses;

    public Student(String name, String email) {
        this.name = name;
        this.email = email;
        this.courses = new ArrayList<>();
    }

    public void enrollCourse(String courseName) {
        courses.add(courseName);
    }

    public void dropCourse(String courseName) {
        courses.remove(courseName);
    }

    public List<String> getEnrolledCourses() {
        return courses;
    }

    public String getName() {
        return name;
    }

    public String getEmail() {
        return email;
    }
}

class Course {
    private String name;
    private int capacity;
    private List<Student> students;

    public Course(String name, int capacity) {
        this.name = name;
        this.capacity = capacity;
        this.students = new ArrayList<>();
    }

    public void enrollStudent(Student student) {
        if (students.size() < capacity) {
            students.add(student);
            student.enrollCourse(name);
            System.out.println(student.getName() + " enrolled in " + name);
        } else {
            System.out.println("Course is full. Cannot enroll " + student.getName());
        }
    }

    public void dropStudent(Student student) {
        students.remove(student);
        student.dropCourse(name);
        System.out.println(student.getName() + " dropped from " + name);
    }

    public List<Student> getEnrolledStudents() {
        return students;
    }

    public String getName() {
        return name;
    }

    public int getCapacity() {
        return capacity;
    }
}

public class CourseRegistrationSystem {
    private List<Course> courses;

    public CourseRegistrationSystem() {
        this.courses = new ArrayList<>();
    }

    public void addCourse(Course course) {
        courses.add(course);
    }

    public void enrollStudent(Student student, Course course) {
        for (Course c : courses) {
            if (c.getName().equals(course.getName())) {
                c.enrollStudent(student);
                break;
            }
        }
    }

    public void dropStudent(Student student, Course course) {
        for (Course c : courses) {
            if (c.getName().equals(course.getName())) {
                c.dropStudent(student);
                break;
            }
        }
    }

    public static void main(String[] args) {
        CourseRegistrationSystem system = new CourseRegistrationSystem();

        // Create courses
        Course course1 = new Course("Java Programming", 30);
        Course course2 = new Course("Data Structures", 20);

        // Add courses to the system
        system.addCourse(course1);
        system.addCourse(course2);

        // Create students
        Student student1 = new Student("John Doe", "john@example.com");
        Student student2 = new Student("Jane Smith", "jane@example.com");

        // Enroll students in courses
        system.enrollStudent(student1, course1);
        system.enrollStudent(student2, course2);

        // Drop students from courses
        system.dropStudent(student1, course1);
        system.dropStudent(student2, course2);
    }
}