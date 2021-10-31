extends CanvasItem
class_name Actor

export var start_hidden : bool = false


func _ready():
	if start_hidden:
		modulate.a = 0.0
