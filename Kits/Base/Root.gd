extends CanvasLayer


func _input(event):
	if event is InputEventKey:
		match event.scancode:
			KEY_ESCAPE:
				get_tree().quit()
			KEY_R:
				get_tree().reload_current_scene()

