
import java.io.*;
import java.util.*;
import java.util.stream.*;
import java.nio.*;
import java.nio.charset.*;
import java.nio.file.*;

public class main {
    
    public static void main(String[] args) throws IOException {
        Map<String, Integer> map = new TreeMap<>();
        Map<String, String> newMap = new TreeMap<>();
        List<String> list = doSimpleArray();

        final Scanner read = new Scanner(new File(args[0]));

        while(read.hasNext()) {
            String in = read.next();
            if(map.containsKey(in)) {
                map.replace(in, map.get(in), map.get(in)+1);
            }
            else {
                map.put(in, 1);
            }
        }
        read.close();
        
        Map<String, Integer> sorted = new TreeMap<>();
        
        sorted = map.entrySet().stream()
            .sorted((Map.Entry.<String, Integer>comparingByValue().reversed()))
            .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue, (e1, e2) -> e1, LinkedHashMap::new));
        
        //System.out.println(sorted.toString());
        
        Set<String> s = sorted.keySet();
        for (String str : s) {
            str = str.replace(",", "").replace(".", "").replace("?", "").replace("...", "").replace("\"", "").replace(";", "").replace("!", "").replace(":", "");
            //System.out.println(str);
            newMap.put(str, list.get(0));
            // System.out.print(list.get(0) + " ");
            list.remove(0);
        }
        //System.out.println(newMap);

        lerFicETrocar(args[0], newMap);
    }

    public static List<String> doSimpleArray( ){
        List<String> listSingle = new ArrayList<String>( 
            Arrays.asList("A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z",
            "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",
            "0","1","2","3","4","5","6","7","8","9")); 

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
        List<String> total = new ArrayList<>();
        total.addAll(listSingle);
        total.addAll(listDouble);
        total.addAll(listTriple);
        total.sort(Comparator.comparingInt(String::length));
        //System.out.println(total);
        return total; 
    }

    public static void lerFicETrocar(String file, Map<String,String> newMap) throws IOException{

        File log= new File(file);

        try{
            FileReader fr = new FileReader(log);
            String s;
            String totalStr = "";
            try (BufferedReader br = new BufferedReader(fr)) {

                while ((s = br.readLine()) != null) {
                    String[] strings = s.split(" ");
                    for(String str: strings){
                        totalStr += newMap.get(str) + " ";
                    }
                    totalStr += "\n";

                }
                FileWriter fw = new FileWriter("result.txt");
                fw.write(totalStr);
                fw.close();
            }
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}