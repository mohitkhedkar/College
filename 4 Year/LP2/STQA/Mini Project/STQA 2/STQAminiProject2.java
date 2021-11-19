package com.selenium;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;

public class testing {
    public static void main(String[] args) throws Exception {
        System.setProperty("webdriver.chrome.driver","D:\\SElJar\\drivers\\chromedriver\\chromedriver.exe");
        WebDriver driver = new ChromeDriver();
        driver.get("https://attendance-management-dbmsl.herokuapp.com/");
        driver.manage().window().maximize();
        driver.findElement(By.id("inputEmail3")).sendKeys("surajsir");
        Thread.sleep(1000);
        driver.findElement(By.id("inputPassword3")).sendKeys("surajsir");
        Thread.sleep(1000);
        driver.findElement(By.xpath("//*[@id=\"loginForm\"]/div[3]/input")).click();
        String at = driver.getTitle();

        String et = "Student Attendance Management System";
        if(at.equalsIgnoreCase(et))
        {
            Thread.sleep(1000);
            driver.findElement(By.xpath("//*[@id=\"page-content-wrapper\"]/div/div/div[2]/div[2]/p/a")).click();
            Thread.sleep(1000);
            driver.findElement(By.cssSelector("#page-content-wrapper > div > div > div > div:nth-child(2) > div > form:nth-child(2) > table > thead > tr > th:nth-child(3) > input")).click(); // allselect
            Thread.sleep(1000);
            driver.findElement(By.name("sbt_top")).click(); // save att
            driver.findElement(By.cssSelector("#page-content-wrapper > button > span.hamb-middle")).click(); // sidebar
            Thread.sleep(1000);
            driver.findElement(By.xpath("/html/body/div/nav/ul/li[4]/a")).click(); // Liststudent
            Thread.sleep(1000);
            driver.findElement(By.cssSelector("#page-content-wrapper > button > span.hamb-middle")).click(); //sidebar
            Thread.sleep(1000);
            driver.findElement(By.cssSelector("#sidebar-wrapper > ul > li:nth-child(5) > a")).click(); //report
            driver.findElement(By.cssSelector("#page-content-wrapper > button > span.hamb-middle")).click(); //sidebar
            Thread.sleep(1000);
            driver.findElement(By.xpath("//*[@id=\"sidebar-wrapper\"]/ul/li[2]/a")).click(); //Dsahboard
            Thread.sleep(1000);
            driver.findElement(By.cssSelector("#page-content-wrapper > button > span.hamb-middle")).click(); //sidebar
            Thread.sleep(1000);
            driver.findElement(By.cssSelector("#sidebar-wrapper > ul > li:nth-child(6) > a")).click();// logout
        }
        else {
            driver.close();
            System.out.println("Tesing unsuccesfull");
        }
        Thread.sleep(1000);
        driver.findElement(By.id("rollno")).sendKeys("98");
        driver.findElement(By.xpath("//*[@id=\"studentForm\"]/div[2]/input")).click(); //go
        driver.findElement(By.xpath("//*[@id=\"page-content-wrapper\"]/button")).click();//sidebar
        Thread.sleep(1000);
        driver.findElement(By.cssSelector("#sidebar-wrapper > ul > li:nth-child(2) > a")).click();//Logout
        driver.close();
        System.out.println("Test done sucesfully");
    }
}







