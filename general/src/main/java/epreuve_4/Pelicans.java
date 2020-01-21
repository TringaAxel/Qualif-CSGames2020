package epreuve_4;

import java.util.*;

public class Pelicans {

    /*
        Test des 2 rolls
     */
    private static boolean testDeuxJoueur(ArrayList<Integer> array) {
        boolean test = false;
        if (array.get(0).equals(array.get(1))){
            test = true;
        }
        return test;
    }
    /*
        Affichage en fin de jeu;
     */
    private static void affichageFin (ArrayList<Integer> array){
        if (array.get(2) > array.get(3)){
            System.out.println("Joueur 1 gagne avec " + array.get(2) + " artichauts !");
            System.out.println("Joueur 2 perd avec " + array.get(3) + " artichauts !");
            System.out.println("Le nombre de rolls jouee : " + array.get(4));
            System.out.println("Fin de la partie !");

        } else if (array.get(2) < array.get(3)) {
            System.out.println("Joueur 2 gagne avec " + array.get(3) + " artichauts !");
            System.out.println("Joueur 1 perd avec " + array.get(2) + " artichauts !");
            System.out.println("Le nombre de rolls jouee :" + array.get(4));
            System.out.println("Fin de la partie !");
        } else {
            System.out.println("Match null");
            System.out.println("Joueur 1 dispose de " + array.get(2) + " artichauts !");
            System.out.println("Joueur 2 dispose " + array.get(3) + " artichauts !");
            System.out.println("Le nombre de rolls jouee : " + array.get(4));
            System.out.println("Fin de la partie !");
        }
    }
    /*
        Fonction du jeu principal;
     */
    private static boolean game (ArrayList<Integer> joueur) {
        roll(joueur);
       boolean endGame = testDeuxJoueur(joueur);
        if (endGame){
           affichageFin(joueur);
       } else if (joueur.get(0) == 1 && joueur.get(1) == 6 || joueur.get(0) == 6 && joueur.get(1) == 1){
           restart3Lancer(joueur);
           endGame = true;
       }
       else {
          difference(joueur);
       }
       return endGame;
    }

    private static void restart3Lancer (ArrayList<Integer> array){
            array.set(2,0);
            array.set(3,0);
            array.set(4,0);
            for (int i = 0 ; i < 3 ; i++){
                roll(array);
                if (!testDeuxJoueur(array)){
                    voleur(array);
                    difference(array);
                }
            }
            affichageFin(array);

    }
    /*
        Fonction de difference d'artichauts
     */
    private static void difference(ArrayList<Integer> joueur){
        if (joueur.get(0) > joueur.get(1)) {
            joueur.set(2, joueur.get(2) + (joueur.get(0) - joueur.get(1)));
        } else {
            joueur.set(3, joueur.get(3) + (joueur.get(1) - joueur.get(0)));
        }
    }
    /*
        Fonction de lancee de rolls;
     */
    private static void roll (ArrayList<Integer> array){
        double value1 = Math.random()*((6-1)+ 1)+1;
        double value2 = Math.random()*((6-1)+ 1)+1;
        array.set(0,(int)value1);
        array.set(1,(int)value2);
        array.set(4,array.get(4)+1);
    }
    /*
        Si l'un des joueur fait 6 et que l'autre ne dispose pas du chiffre 1,
        alors le joueur ayant fait 6 get 17% des artichauts adverse;
     */
    private static void voleur (ArrayList<Integer> joueur){
        if (joueur.get(0) == 6){
            joueur.set(2,joueur.get(3)+(int)(joueur.get(3)*0.17));
            joueur.set(3,(int)(joueur.get(3)*0.83));
        } else if (joueur.get(1) == 6){
            joueur.set(3,joueur.get(3)+(int)(joueur.get(2)*0.17));
            joueur.set(2,(int)(joueur.get(2)*0.83));
        }
    }
    /*
        Dans le ArrayList joueur nous diposons :
            - Index 0 Le rolls du premier joueur;
            - Index 1 Le rolls du deuxieme joueur;
            - Index 2 Le nombre total d'artichauts du premier joueur;
            - Index 3 Le nombre total d'artichauts du deuxieme joueur;
            - Index 4 Le nombre de rolls total jouee;
     */
    public static void main(String[] args) {
        System.out.println("Bienvenue dans le jeu du pelicans !");
        ArrayList<Integer> joueur = new ArrayList<>();
        for (int i = 0 ; i < 5 ; i++){
            joueur.add(0);
        }
        boolean endGame = false;
        do {
           endGame = game(joueur);
        } while (!endGame);

    }
}
