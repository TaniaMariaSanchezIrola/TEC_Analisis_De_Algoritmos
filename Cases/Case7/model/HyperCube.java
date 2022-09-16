package model;

import java.util.ArrayList;

public class HyperCube {

    private final int DIMENSION_SIZE = 27;   //3x3x3
    private Graph<Character> graph;

    public HyperCube(){
        this.graph = new Graph<Character>();
        this.loadGraph();
    }

    public Graph<Character> getGraph(){
        return this.graph;
    }

    private void loadGraph(){
        String nodeNames = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1";
        int index = 0;
        for(index = 0; index < 27; index++){
            this.graph.addNode(nodeNames.charAt(index));
        }
        ArrayList<Node<Character>> nodes = this.graph.getNodes();
        //Linking X Dimension with 'A' and 'B' weights.
        for(index = 0; index < DIMENSION_SIZE; index += 3){
            //Assing 'A' weight
            this.graph.addArc(nodes.get(index), nodes.get(index + 1), 'A');
            
            //Assing 'B' weight
            this.graph.addArc(nodes.get(index + 1), nodes.get(index + 2), 'B');
        }
        //Linking Y Dimension with '1' and '2' weights.
        for(index = 0; index < DIMENSION_SIZE; index += 9){
            //Assing '1' weight
            this.graph.addArc(nodes.get(index), nodes.get(index + 3), '1');
            this.graph.addArc(nodes.get(index + 1), nodes.get(index + 4), '1');
            this.graph.addArc(nodes.get(index + 2), nodes.get(index + 5), '1');
            //Assing '2' weight
            this.graph.addArc(nodes.get(index + 3), nodes.get(index + 6), '2');
            this.graph.addArc(nodes.get(index + 4), nodes.get(index + 7), '2');
            this.graph.addArc(nodes.get(index + 5), nodes.get(index + 8), '2');
        }
        //Linking Z Dimension with 'K'weight.
        for(index = 0; index < 9; index += 3){
            this.graph.addArc(nodes.get(index), nodes.get(index + 9), 'K');
            this.graph.addArc(nodes.get(index + 1), nodes.get(index + 10), 'K');
            this.graph.addArc(nodes.get(index + 2), nodes.get(index + 11), 'K');
        }
        //Linking Z Dimension with 'F' weight.
        for(index = 9; index < 18; index += 3){
            this.graph.addArc(nodes.get(index), nodes.get(index + 9), 'F');
            this.graph.addArc(nodes.get(index + 1), nodes.get(index + 10), 'F');
            this.graph.addArc(nodes.get(index + 2), nodes.get(index + 11), 'F');
        }

        //A B C D E F G H I J K L M N O P Q R T U V W X Y Z 1

        /*
            A       B
        A       B       C               A => J = K,     B => K1 = K,    C => L = K
                                1
        D       E       F               D => M = K,     E => N = K,     F => O = K
                                2
        G       H       I               G => P = K,     H => Q = K,     I => R = K
        -----------------
            A       B
        J       K1       L              J => S = F,     K1 => T = F,    L => U = F
                                1       J => A = K,     K1 => B = K,    L => C = K
        M       N       O               M => V = F,     N => W = F,     O => X = F
                                2       M => D = K,     N => E = K,     O => F = K
        P       Q       R               P => Y = F,     Q => Z = F,     R => 1 = F
        -----------------               P => G = K,     Q => H = K,     R => I = K
            A       B
        S       T       U               S => J = F,     T => K1 = F,    U => L = F
                                1
        V       W       X               V => M = F,     W => N = F,     O => X = F
                                2
        Y       Z       1               Y => P = F,     Z => Q = F,     1 => R = F
        */
        
    }
}
