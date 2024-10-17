/**
 * Clase ImitadorModelo Contiene informaci�n de un imitador
 * 
 * @author Iv�n Alexander Cort�s P�rez
 */
package model;

public class ImitadorModelo {
    private boolean[] opcionesOriginal;
    private String textoOriginal;
    private String comboSeleccionado;
    private int numeroOriginal;

    public ImitadorModelo() {
        this.opcionesOriginal = new boolean[6];  // Para Opciones 1 a 6
        this.textoOriginal = "";
        this.comboSeleccionado = "Item 1";
        this.numeroOriginal = 0;
    }

    public boolean[] getOpcionesOriginal() {
        return opcionesOriginal;
    }

    public void setOpcion(int indice, boolean estado) {
        this.opcionesOriginal[indice] = estado;
    }

    public String getTextoOriginal() {
        return textoOriginal;
    }

    public void setTextoOriginal(String textoOriginal) {
        this.textoOriginal = textoOriginal;
    }

    public String getComboSeleccionado() {
        return comboSeleccionado;
    }

    public void setComboSeleccionado(String comboSeleccionado) {
        this.comboSeleccionado = comboSeleccionado;
    }

    public int getNumeroOriginal() {
        return numeroOriginal;
    }

    public void setNumeroOriginal(int numeroOriginal) {
        this.numeroOriginal = numeroOriginal;
    }
}

