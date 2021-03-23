/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Question2;

/**
 *
 * @author DELL
 */
public class Driver {
     public static void clearScreen() {
        System.out.print("ALO123 My name is Nhan :v");
        System.out.flush();
    }
    public static void main(String[] args) {
        CourseList l = new CourseList();
        while (true) {
            System.out.println("COURSE MANAGEMENT SYSTEM");
            System.out.println("1. Show all available course in the system");
            System.out.println("2. Search and display course information by id");
            System.out.println("3. Add new course to the system");
            System.out.println("4. Sort all courses in the system");
            System.out.println("5. Update specific course by given id");
            System.out.println("6. Delete specific course by given id");
            System.out.println("0. Exit Program");
            System.out.print("Select your choice: ");
            int choice = Validation.newIntBetween(0, 6);
            switch (choice) {
                case 0:
                    return;
                case 1:
                    l.listAll();
                    break;
                case 2:
                    l.displayById();
                    break;
                case 3:
                    l.addCourse();
                    break;
                case 4:
                    l.sortByName();
                    break;
                case 5:
                    l.edit();
                    break;
                case 6:
                    l.remove();
                    break;

            }
        }
    }
}
