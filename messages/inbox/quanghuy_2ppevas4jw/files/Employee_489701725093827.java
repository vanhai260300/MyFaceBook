/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java;

/**
 *
 * @author My PC
 */
public class Employee extends Person{
    private float salary;
    private float rate;

    public Employee() {
        super(null, 0, null);
    }

    public Employee(float salary, float rate, String name, int age, String address) {
        super(name, age, address);
        this.salary = salary;
        this.rate = rate;
    }
    
    public float sumSalary(){
        return salary*rate;
    }
    public String display(){
        return super.display() + " sum salary: " +sumSalary();
    }
}
