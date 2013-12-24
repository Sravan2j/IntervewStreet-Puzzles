import java.awt.Point;
import java.util.ArrayList;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {        
        Scanner scan = new Scanner(System.in);
        int numberOfPoints = scan.nextInt();
        ArrayList<Point> pointsList = new ArrayList<Point>(numberOfPoints);
        double x = 0.0;
        double y = 0.0;        
        for (int i = 0; i < numberOfPoints; i++) {
            Point point = new Point(scan.nextInt(), scan.nextInt());
            x += point.x;
            y += point.y;
            pointsList.add(point);
        }        
        x = x / numberOfPoints;
        y = y / numberOfPoints;        
        double tempDistance = Math.sqrt(Math.pow((x - pointsList.get(0).x), 2)
                + Math.pow((y - pointsList.get(0).y), 2));
        int pointIndex = 0;
        for (int j = 1; j < numberOfPoints; j++) {
            double distance = Math.sqrt(Math.pow((x - pointsList.get(j).x), 2)
                    + Math.pow((y - pointsList.get(j).y), 2));
            if (distance < tempDistance) {
                tempDistance = distance;
                pointIndex = j;
            }
        }
        long distance = 0;
        for (int k = 0; k < numberOfPoints; k++) {
            if (pointIndex == k) {
                continue;
            } else {
                distance = distance
                        + getDistance(pointsList.get(pointIndex),
                                pointsList.get(k));
            }

        }

        System.out.println(distance);
    }
    private static long getDistance(Point point1, Point point2) {
        long yDifference = Math.abs(point1.y - point2.y);
        long xDifference = Math.abs(point1.x - point2.x);
        if (yDifference > xDifference) {
            return yDifference;
        } else {
            return xDifference;
        }
    }
}