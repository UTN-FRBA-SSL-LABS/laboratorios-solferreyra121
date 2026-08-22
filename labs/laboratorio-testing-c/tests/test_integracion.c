#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */
void test_compra_con_descuento(void){
    printf("\n[total: 1300, total con descuento: 1170]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Pan", 200, 3};
    carrito_agregar(&c, p);
    Producto l = {"Leche", 350, 2};
    carrito_agregar(&c, l);
    ASSERT_IGUAL(1300, carrito_total(&c));
    ASSERT_IGUAL(1170, carrito_descuento(carrito_total(&c), 10));
}
/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_agregar_hasta_llenar() */
void test_agregar_hasta_llenar(void){
    printf("\n [total: 4 productos]\n");
    Carrito c;
    carrito_init(&c);
    Producto p1 = {"Pan", 200, 2};
    carrito_agregar(&c, p1);
    Producto p2 = {"Pan", 200, 1};
    carrito_agregar(&c, p2);
    Producto q1 = {"Queso", 1500, 1};
    carrito_agregar(&c, q1);
    Producto l = {"Leche", 350, 2};
    carrito_agregar(&c, l);
    ASSERT_IGUAL(4,carrito_contar(&c));
    Producto q2 = {"Queso", 1500, 1};
    carrito_agregar(&c, q2);
    ASSERT_IGUAL(0, carrito_agregar(&c, q2));
    ASSERT_IGUAL(4,carrito_contar(&c));
}

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
