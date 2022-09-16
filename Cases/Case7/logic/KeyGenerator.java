package logic;

import model.HyperCube;
import model.Node;
import model.Percentage;
import utils.utils;

import java.util.ArrayList;
import java.util.HashMap;

public class KeyGenerator {

    private HyperCube cube;
    private ArrayList<Character> result;
    private ArrayList<Character> answer;
    private ArrayList<HashMap<Character, Percentage>> charTables;
    private final String chars;

    public KeyGenerator(HyperCube pData, ArrayList<Character> pAnswer){
        this.cube = pData;
        this.result = new ArrayList<Character>();
        this.answer = pAnswer;
        this.chars = "12ABFK ";
        this.charTables = new ArrayList<HashMap<Character, Percentage>>();
        for(int index = 0; index < 6; index++){
            HashMap<Character, Percentage> table = new HashMap<Character, Percentage>();
            for(int character = 0; character < 7; character++){
                table.put(this.chars.charAt(character), 
                            new Percentage((((double)1/7) * character),
                                            (((double)1/7) * (character + 1)),
                                            (double)1/7));
            }
            this.charTables.add(table);
        }
    }

    public void createKey(){
        //Choose StartPoint
        int attempts = 0;
        while(attempts < 10){
            int startPoint = (int)((utils.getRandom() * 100) % 18);
            Node<Character> firstNode = this.cube.getGraph().getNodes().get(startPoint);
            char currentChar = ' ';
            System.out.println("StartPoint: " + firstNode.toString());
            //Use random to choose the most probable option for each part of the Key, overflowing characters will be blanks.
            for(int index = 0; index < 6; index++){
                currentChar = getChar(index);
                if(currentChar == this.answer.get(index)){
                    this.balanceProbability(currentChar, index, true);
                }
                else{
                    this.balanceProbability(currentChar, index, false);
                }
                this.result.add(currentChar);
            }
            if(this.result.equals(this.answer)){
                System.out.println("Found " + this.result + "\nAt " + "attempt " + attempts);
                return;
            }
            this.result.clear();
            attempts++;
        }
        System.out.println("Not found in 10 attempts.");
    }

    private char getChar(int pIndex){
        double rand = utils.getRandom();
        HashMap<Character, Percentage> table = this.charTables.get(pIndex);
        for(char character : table.keySet()){
            if(utils.inRange(table.get(character).iniRange, table.get(character).endRange, rand)){
                return character;
            }
        }
        return ' ';
    }

    //Review the Percentage ranges and sustitute 'A' to make it work
    private void balanceProbability(char pChar, int pTableIndex, boolean pSuccess){
        HashMap<Character, Percentage> table = this.charTables.get(pTableIndex);
        double load = 10;
        double pay = 0.0;
        double complement = 0.0;
        if(pSuccess){       //This will add probability to the char in the table. A = 94 c = 6
            complement = 100 - table.get(pChar).percentage;
            if(complement > load){
                table.get(pChar).percentage += load;
                pay = load/6;
            }
            else{
                pay = -1;
                table.get(pChar).percentage = 100;
            }
            for(char character : table.keySet()){
                if(character != 'A'){
                    if(pay == -1){
                        table.get(character).percentage = 0;
                    }
                    else{
                        table.get(character).percentage -= pay;
                    }
                }
            }
        }
        else{               //This will decrease probability to the char in the table.
            complement = 100 - table.get(pChar).percentage;
            if(complement < load){
                table.get(pChar).percentage -= load;
                pay = load/6;
            }
            else{
                pay = table.get(pChar).percentage / 6;
                table.get(pChar).percentage = 0;
            }
            for(char character : table.keySet()){
                if(table.get(character).percentage != 'A'){
                    table.get(character).percentage += pay;
                }
            }
        }
        //Balance ranges
        double balance = 0;
        for(char character : table.keySet()){
            table.get(character).iniRange = balance;
            table.get(character).endRange = balance + table.get(character).percentage;
            balance += table.get(character).percentage;
        }
    }
    
}
