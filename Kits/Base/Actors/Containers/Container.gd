extends Node2D

export var is_root : bool = false

onready var sequence : Sequence = $Sequence

func _ready():
	if is_root:
		sequence.start()
