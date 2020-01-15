
import java.util.*;



public class Base0v10 {

    private static void input (ArrayList<Integer> number) {
        System.out.println("Les inputs acceptes sont : 0v... ou directement le chiffre\n");
        System.out.print("Merci de rentrer la premiere valeur :");
        try {
            Scanner sc = new Scanner(System.in);
            String octale1 = sc.nextLine();
            System.out.println("Merci de bien vouloir rentrer la deuxieme valeur :");
            String octale2 = sc.nextLine();
            if (testInput(octale1) && testInput(octale2)){
                number.add(Integer.parseInt(octale1.substring(2)));
                number.add(Integer.parseInt(octale2.substring(2)));
                sc.close();
            } else if (testInputInt(octale1) && testInputInt(octale2)) {
                number.add(Integer.parseInt(octale1));
                number.add(Integer.parseInt(octale2));
                sc.close();
            }
        }
        catch (Exception e){
            System.err.println("Erreur input incorrect !");
        }
    }
    private static boolean testInputInt (String octale) {
        return !octale.contains("7") && !octale.contains("8") && !octale.contains("9");
    }
    private static boolean testInput(String octale) {
        return octale.contains("0v") && testInputInt(octale);
    }

    private static ArrayList<Integer> conversionDecimal (ArrayList<Integer> number) {
        ArrayList<Integer> decimal = new ArrayList<Integer>();
        for (int i = 0 ; i < number.size() ; i++){
            int dec = 0;
            int compt = 0;
            for (int j = number.get(i) ; j != 0 ; j/=10 ){
                dec = dec + (j%10) * (int)Math.pow(8,compt);
                compt++;
            }
            decimal.add(dec);
        }
        return decimal;
    }

    private static ArrayList<Integer> conversionOctal (int number){
        ArrayList<Integer> octal = new ArrayList<Integer>();
            for (int i = number ; i != 0 ; i/=8 ){
                octal.add(0,i%8);
            }
        return octal;
    }
    private static void affichage(ArrayList<Integer> octale, String message){
        System.out.print(message);
        for (int i = 0 ; i < octale.size() ; i++){
            System.out.print(octale.get(i));
        }
        System.out.print("\n");
    }
    private static void addition(ArrayList<Integer> number){
        int add = number.get(0) + number.get(1);
        ArrayList<Integer> octale = conversionOctal(add);
        estVide(octale);
        affichage(octale,"Addition : 0v");
    }
    private static void soustraction(ArrayList<Integer> number){
        int add = number.get(0) - number.get(1);
        ArrayList<Integer> octale = conversionOctal(add);
        estVide(octale);
        affichage(octale,"Soustraction : 0v");
    }
    private static void multiplication(ArrayList<Integer> number){
        int add = number.get(0) * number.get(1);
        ArrayList<Integer> octale = conversionOctal(add);
        estVide(octale);
        affichage(octale,"Multiplication : 0v");
    }
    private static void division(ArrayList<Integer> number){
        int add = number.get(0) / number.get(1);
        ArrayList<Integer> octale = conversionOctal(add);
        estVide(octale);
        affichage(octale,"Division : 0v");
    }
    private static void estVide(ArrayList<Integer> number){
        if (number.isEmpty()){
            number.add(0);
        }
    }

    public static void main(String[] args) {
        ArrayList<Integer> number = new ArrayList<Integer>();
        input(number);
        number = conversionDecimal(number);
        addition(number);
        soustraction(number);
        multiplication(number);
        division(number);
    }
}
