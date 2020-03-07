
import java.io.*;
import java.util.*;
import java.util.stream.*;
import java.nio.*;

public class Main {
    
    public static void main(String[] args) throws IOException {
        HashMap<String, Integer> map = new HashMap<>();


        Scanner read = new Scanner(new File("Input1.txt"));

        while(read.hasNext()) {
            String in = read.next();
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
        

        System.out.println(sorted.toString());
    }
}