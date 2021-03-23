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
public class Person {
    private String name;
    private int age;
    private String address;
    public Person(String name, int age, String address) {
        this.name = name;
        this.age = age;
        this.address = address;
    }
   public String display(){
       return "Name: " +name+ " Age: "+ age+ " Address: "+ address;
   }
}
