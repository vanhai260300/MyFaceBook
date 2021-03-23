/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Question2;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

/**
 *
 * @author DELL
 */
public class CourseList {
    ArrayList<Course> ls= new ArrayList<>();;
    public CourseList() {
         ls = new ArrayList<>();
    }
    public void listAll() {
        if (ls.isEmpty())
            System.out.println("There is no course in system");
        else {
            for (Course e : ls) {
                System.out.println(e);
            }
        }
    }

    public int searchById(String id) {
            for (Course e : ls) {
                if (e.getId().equals(id))
                    return ls.indexOf(e);
            }
            return -1;
    }
    public void displayById() {
        System.out.print("Type course id to search: ");
        String id = Validation.newString();
        int index = searchById(id);
        if (index == -1)
            System.out.println("Course with id "+id+" not found in system");
        else System.out.println(ls.get(index));
    }
    public void addCourse() {
        while (true) {
            System.out.println("Add new course to system");
            while (true) {
                String id;
                while (true) {
                    System.out.print("Enter id");
                    id = Validation.newString();
                    if (searchById(id) != -1) {
                        System.out.print("This id exists in system, do you want to continue? (y/n): ");
                        if (!Validation.confirmYN()) return;
                    }
                    else break;
                }
                System.out.print("Enter name: ");
                String name = Validation.newString();
                System.out.print("Enter credit: ");
                int cre = Validation.newInt();
                ls.add(new Course(id, name, cre));
                System.out.print("Course added. Continue? (y/n): ");
                if (!Validation.confirmYN()) return;
                }
            }
        }
    public void sortByName() {
        //Collections.sort(ls);
        Collections.sort(ls, new Comparator<Course>() {
           
            public int compare(Course o1, Course o2) {
                return o1.getName().compareTo(o2.getName());}
        });
        listAll();
    }
    public void edit() {
        while (true) {
            System.out.print("Type course id to update: ");
            String id = Validation.newString();
            int index = searchById(id);
            if (index==-1)
                System.out.println("Course with id "+id+" not found in system");
                System.out.print("Continue? (y/n): ");
                if (!Validation.confirmYN()) return;
            else {
                System.out.print("Enter name: ");
                String name = Validation.newString();
                System.out.print("Enter credit: ");
                int cre = Validation.newInt();
                ls.get(index).setName(name);
                ls.get(index).setCredit(cre);
                System.out.print("Course updated. Continue? (y/n): ");
                if (!Validation.confirmYN()) return;
            }

        }
    }
    public void remove() {
        while (true) {
            System.out.print("Type course id to remove: ");
            String id = Validation.newString();
            int index = searchById(id);
            if (index==-1) {
                System.out.println("Course with id "+id+" not found in system");
                System.out.print("Continue? (y/n): ");
                if (!Validation.confirmYN()) return;
            }
            else {
                ls.remove(index);
                System.out.print("Course removed. Continue? (y/n): ");
                if (!Validation.confirmYN()) return;
            }

        }
    }
}
