extends Node2D
class_name ContainerActor

export var is_root : bool = false

onready var sequence : Sequence = $Sequence


func _ready():
	if is_root:
		sequence.start()
