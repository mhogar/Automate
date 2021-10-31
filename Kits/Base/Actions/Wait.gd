extends Action
class_name WaitAction

onready var sequence : Sequence

var started : bool


func _ready():
	sequence = get_parent()
	started = false


func _process(delta):
	if !started:
		return
	
	# check less than or one to account for self
	if sequence.active_count <= 1:
		started = false
		emit_signal("completed")


func start():
	started = true
