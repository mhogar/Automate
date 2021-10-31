extends Node2D
class_name Actor

export var start_hidden : bool = true


func _ready():
	if start_hidden:
		modulate.a = 0.0
