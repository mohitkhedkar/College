// Assignement 3: Develop elementary chatbot  for suggesting investment as per the customers need.

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;
import java.util.Scanner;

public class chatbot {

	Map<String, String> nouns = new HashMap<String, String>();
	Map<String, String> welcome = new HashMap<String, String>();
	Map<String, String> farewell = new HashMap<String, String>();

	boolean exit = false;

	ArrayList<String> keywords;

	public chatbot() {

		nouns.put("money", "\tWhere??");
		nouns.put("finance", "\tMany firms provide loan options");
		nouns.put("invest",
				"\tYes, offcourse. Basically there are many options to invest. Regional Or Investment Banks?");
		nouns.put("shares", "\tWhich company shares?");
		nouns.put("loan", "\tWhich loan? Housing ,Personal,Educational. I recommend to visit SBI website for this");
		nouns.put("investment", "\tWell there are many such as UBS, Barclays, Deutsche Bank, HSBC, Wells Fargo");
		nouns.put("regional", "\tThere are many SBI, IDBI, Kotak Mahindra");

		welcome.put("hii", "\tWelcome! How can I help you??");
		welcome.put("hey", "\tHey, how I can help you??");
		welcome.put("hello", "\tHello,How can I help you??");
		welcome.put("thankyou", "\tWelcome");

		farewell.put("bye", "\tBye");
		farewell.put("bbye", "\tBbye");

	}

	public static void main(String[] args) {

		Scanner s = new Scanner(System.in);
		chatbot c = new chatbot();

		while (true) {
			String input = s.nextLine();
			String output = c.giveans(input);
			System.out.println(output);
			if (c.exit)
				break;
		}
	}

	public String giveans(String input) {
		Random rand = new Random();
		keywords = new ArrayList<String>();
		String tokens[] = input.split("\\s");

		for (int i = 0; i < tokens.length; i++) {
			if (welcome.containsKey(tokens[i].toLowerCase())) {
				return welcome.get(tokens[i]);
			} else if (farewell.containsKey(tokens[i].toLowerCase())) {
				return farewell.get(tokens[i]);
			} else if (nouns.containsKey(tokens[i].toLowerCase())) {
				return nouns.get(tokens[i]);
			}
		}
		return ("I am sorry. I don't get this.");
	}
}
