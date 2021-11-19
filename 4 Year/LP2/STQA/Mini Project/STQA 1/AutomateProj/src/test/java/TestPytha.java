
import static org.junit.Assert.*;

import org.junit.Test;

public class TestPytha {

    @Test
    public void testPythagoras() {
        JunitClass junit = new JunitClass();
        int result = junit.pythagoras(4,3);
        assertEquals(5,result);
    }

}