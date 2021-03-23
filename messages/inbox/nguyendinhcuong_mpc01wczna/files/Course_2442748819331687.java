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
public class Course {
    private String id;
    private String name;
    private int credit;

    public Course() {
    }

    public Course(String id, String name, int credit) {
        this.id = id;
        this.name = name;
        this.credit = credit;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getCredit() {
        return credit;
    }

    public void setCredit(int credit) {
        this.credit = credit;
    }

    @Override
    public boolean equals(Object obj) {
        return super.equals(obj); //To change body of generated methods, choose Tools | Templates.
    }

    public int compareTo(Course Cr) {
       return this.getName().compareTo(Cr.getName());
    }

    @Override
    public String toString() {
        return "Course{" + "id=" + id + ", name=" + name + ", credit=" + credit + '}';
    }
    
}
