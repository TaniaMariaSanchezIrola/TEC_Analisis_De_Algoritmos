package program;

import model.HyperCube;

import java.util.ArrayList;

import logic.KeyGenerator;

class App {
    public static void main(String[] args) {
        System.out.println("Case 7\nLuis Diego Mora Aguilar.\n2018147110\n\n"); 
        HyperCube data = new HyperCube();
        ArrayList<Character> answer = new ArrayList<Character>();
        answer.add('2');
        answer.add('A');
        answer.add('K');
        answer.add(' ');
        answer.add(' ');
        answer.add(' ');
        KeyGenerator generator = new KeyGenerator(data, answer);
        generator.createKey();
    }

}