/**
 * Clase ImitadorControlador Contiene información de un imitador
 * 
 * @author Iván Alexander Cortés Pérez
 */
package controller;

import model.ImitadorModelo;
import view.ImitadorVista;

public class ImitadorControlador {
	// Atributos de la clase
	/**
	 * Vista del imitador
	 */
    private ImitadorVista vista;
	/**
	 * Modelo del imitador
	 */
    private ImitadorModelo modelo;

	// Constructor
	/**
	 * Constructor con 2 parámetros
	 *
	 * @param vista
	 * @param modelo
	 **/
    public ImitadorControlador(ImitadorVista vista, ImitadorModelo modelo) {
        this.vista = vista;
        this.modelo = modelo;
        inicializarControlador();
    }

    private void inicializarControlador() {
        // Sincronizar los radio buttons
        for (int i = 0; i < vista.getRadioButtonsOriginal().length; i++) {
            int finalI = i;
            vista.getRadioButtonsOriginal()[i].addActionListener(e -> {
                modelo.setOpcion(finalI, vista.getRadioButtonsOriginal()[finalI].isSelected());
                vista.getRadioButtonsEspejo()[finalI].setSelected(vista.getRadioButtonsOriginal()[finalI].isSelected());
            });
        }

        // Sincronizar los checkboxes
        for (int i = 0; i < vista.getCheckBoxesOriginal().length; i++) {
            int finalI = i;
            vista.getCheckBoxesOriginal()[i].addActionListener(e -> {
                modelo.setOpcion(finalI + 3, vista.getCheckBoxesOriginal()[finalI].isSelected());
                vista.getCheckBoxesEspejo()[finalI].setSelected(vista.getCheckBoxesOriginal()[finalI].isSelected());
            });
        }

        // Sincronizar el campo de texto
        vista.getCampoTextoOriginal().addActionListener(e -> {
            modelo.setTextoOriginal(vista.getCampoTextoOriginal().getText());
            vista.getCampoTextoEspejo().setText(vista.getCampoTextoOriginal().getText());
        });

        // Sincronizar el combo box
        vista.getComboBoxOriginal().addActionListener(e -> {
            modelo.setComboSeleccionado((String) vista.getComboBoxOriginal().getSelectedItem());
            vista.getComboBoxEspejo().setSelectedItem(vista.getComboBoxOriginal().getSelectedItem());
        });

        // Sincronizar el spinner
        vista.getSpinnerOriginal().addChangeListener(e -> {
            modelo.setNumeroOriginal((Integer) vista.getSpinnerOriginal().getValue());
            vista.getSpinnerEspejo().setValue(vista.getSpinnerOriginal().getValue());
        });
    }
}
