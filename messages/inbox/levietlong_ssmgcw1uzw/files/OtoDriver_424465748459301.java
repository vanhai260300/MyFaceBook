/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author E6410
 */
public class OtoDriver {
    public static void main(String[] args) {
        DSXeOTo s1=new DSXeOTo();
        while(true)
        {
            Manager.menu();
            int choice=Validation.checkInputLimit(1, 3);
            switch (choice) {
                case 1:
                    s1.createListOto();
                    break;
                case 2:
                    s1.report();
                    break;
                case 3:
                    return;
            }

        }
    }
}
