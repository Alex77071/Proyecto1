/**
 * Clase MVCImitador Contiene informaci�n de un imitador
 * 
 * @author Iv�n Alexander Cort�s P�rez
 */
package mvc;

import controller.ImitadorControlador;
import model.ImitadorModelo;
import view.ImitadorVista;

public class MVCImitador {
	  public static void main(String[] args) {
	        ImitadorVista vista = new ImitadorVista();
	        ImitadorModelo modelo = new ImitadorModelo();
	        new ImitadorControlador(vista, modelo);

	        vista.setVisible(true);
	    }
}
