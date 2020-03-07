
import java.io.*;
import java.util.*;
import java.util.stream.*;
import java.nio.*;

public class Main {
    
    public static void main(final String[] args) throws IOException {
        final HashMap<String, Integer> map = new HashMap<>();
        final HashMap<String, String> newMap = new HashMap<>();
        List<String> list = doSimpleArray();

        final Scanner read = new Scanner(new File("Input1.txt"));

        while(read.hasNext()) {
            final String in = read.next();
            if(map.containsKey(in)) {
                map.replace(in, map.get(in), map.get(in)+1);
            }
            else {
                map.put(in, 1);
            }
        }
        
        HashMap<String, Integer> sorted = new HashMap<>();

        sorted = map.entrySet().stream()
            .sorted((Map.Entry.<String, Integer>comparingByValue().reversed()))
            .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue, (e1, e2) -> e1, LinkedHashMap::new));
        

        //System.out.println(sorted.toString());
        
        for (String str : map.keySet()) {
            str = str.replace(",", "").replace(".", "").replace("?", "").replace("...", "").replace("\"", "").replace(";", "").replace("!", "").replace(":", "");
            //System.out.println(str);
            newMap.put(str, list.get(0));
            list.remove(0);
        }
        System.out.println(newMap);
    }

    public static List<String> doSimpleArray(){
        List<String> listSingle = new ArrayList<String>( 
            Arrays.asList("A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z",
            "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",
            "1","2","3","4","5","6","7","8","9")); 

        List<String> listDouble = new ArrayList<>();
        for (String str : listSingle) {
            for (String s : listSingle) {
                listDouble.add(str+s);
            }
        }
        List<String> listTriple = new ArrayList<>();
        for (String str : listDouble) {
            for (String s : listSingle) {
                listTriple.add(str+s);
            }
        } 
        //System.out.println("listDouble: " + listTriple);
        return listTriple;
    }
}