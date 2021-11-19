import static org.junit.Assert.*;

import org.junit.Test;

public class TestAreaSqr {

    @Test
    public void testAreasqr() {
        JunitClass junit = new JunitClass();
        int result = junit.areasqr(4);
        assertEquals(16,result);

    }


}