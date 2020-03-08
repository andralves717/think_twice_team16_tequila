import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.SortedMap;
import java.util.TreeMap;
import java.util.Scanner;
import java.io.*;

public class main {

    public static void main(String[] args) throws IOException {
        HashMap<String, HashMap<String, Integer>> map = new HashMap<>();
        

        Scanner read = new Scanner(new File(args[0]));

        String prev = read.next().trim().toLowerCase();
        while(read.hasNext()) {
            String next = read.next().trim().toLowerCase();
            while(next.length() <3) {
                next = read.next().trim().toLowerCase();
            }

            if(prev.length() >= 3) {
                if(next.length() >= 3) {
                    if(map.containsKey(prev)) {
                        HashMap<String, Integer> aux = map.get(prev);
                        if(aux.containsKey(next)){
                            aux.replace(next, aux.get(next), aux.get(next)+1);
                        }
                        else{
                            aux.put(next, 1);
                        }

                        map.put(prev, aux);
                    }

                    else{
                        HashMap<String, Integer> aux = new HashMap<>();
                        aux.put(next, 1);

                        map.put(prev, aux);
                    }
                }
            }
            prev = next;
        }

        Map<String, HashMap<String, Integer>> treeMap = new TreeMap<>(map);


        //treeMap.forEach((key, value) -> System.out.println(key + ":" + value));
        

        FileWriter file = new FileWriter("/team16_tequila/challenge21/teamresult.txt");
        file.write(treeMap.toString());
        file.close();


        
    }


}