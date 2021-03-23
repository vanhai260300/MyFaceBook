/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Question2;

import java.util.Scanner;

/**
 *
 * @author DELL
 */
public class Validation {
    private static final Scanner input = new Scanner(System.in);
    public static String newString() {
        while (true) {
            String i = input.nextLine().trim();
            if (i.isEmpty())
                System.out.print("Not empty, type again: ");
            else return i;
        }
    }
    public static int newInt() {
        while (true) {
            try {
                int i = Integer.parseInt(input.nextLine().trim());
                return i;
            }
            catch (NumberFormatException e) {
                System.out.print("Must be a valid number, type again");

            }
        }
    }
    public static int newIntBetween(int from, int to) {
        while (true) {
            try {
                int i = Integer.parseInt(input.nextLine().trim());
                if (i < from || i > to)
                    throw new NumberFormatException();
                return i;
            }
            catch (NumberFormatException e) {
                System.out.print("Must be a valid number, type again");

            }
        }
    }
    public static boolean confirmYN() {
        while (true) {
            String i = input.nextLine().trim();
            if (i.equalsIgnoreCase("Y")) return true;
            if (i.equalsIgnoreCase("N")) return false;
            System.out.print("Must be y (yes) or n (no), type again: ");
        }
    }
}
