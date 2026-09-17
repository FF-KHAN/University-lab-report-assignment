#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c;
    double discriminant, root1, root2;
    double realPart, imaginaryPart;

    printf("Enter the values of a, b and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a == 0)
    {
        printf("This is not a quadratic equation.\n");
        return 0;
    }

    discriminant = (b * b) - (4 * a * c);

    if (discriminant > 0)
    {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);

        printf("\nThe roots are real and different.\n");
        printf("Root 1 = %.2lf\n", root1);
        printf("Root 2 = %.2lf\n", root2);
    }
    else if (discriminant == 0)
    {
        root1 = -b / (2 * a);

        printf("\nThe roots are real and equal.\n");
        printf("Root 1 = Root 2 = %.2lf\n", root1);
    }
    else
    {
        realPart = -b / (2 * a);
        imaginaryPart = sqrt(-discriminant) / (2 * a);

        printf("\nThe roots are complex and different.\n");
        printf("Root 1 = %.2lf + %.2lfi\n", realPart, imaginaryPart);
        printf("Root 2 = %.2lf - %.2lfi\n", realPart, imaginaryPart);
    }

    return 0;
}