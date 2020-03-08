import java.io.*;
import java.util.*;

public class main {
	
	public static void main(String args[]) throws IOException { 
        String filename=args[0];
        String str = "";
        String str2 = "";
        int count = 0;
        
        File f1 = new File(filename);
		Scanner scf = new Scanner(f1);
		while(scf.hasNextLine()) {
			String string = scf.nextLine();
			for (String s : string.split(" ")) {
				if (s.contains("\"")  && count%2==0 ) {
					str2 = s.replace("\"", "``");
					str += str2+" ";
					count++;
				}else if(s.contains(",\"")){
					str2 = s.replace("\"", "\'' ");
					str += str2;
					count++;
				}else if(s.contains("\"")){
					str2 = s.replace("\"", "\''");
					str += str2;
					count++;
				}else {
					str += s + " ";
				}
			}
			
			if(scf.hasNext()){
				str += "\n";
			}
		}
		System.out.println(str);
		
	    BufferedWriter writer = new BufferedWriter(new FileWriter("team16_tequila/challenge2/result.txt"));
	    writer.write(str);
	    writer.close();
    } 
}
