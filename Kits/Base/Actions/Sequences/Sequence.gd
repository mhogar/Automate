extends Action
class_name Sequence

onready var actions : Array = get_children()

var next_action : int
var active_count : int
var is_blocked : bool


func start():
	next_action = 0
	active_count = 0
	is_blocked = false
	
	start_next()


func start_next():
	while !is_blocked:
		if next_action >= actions.size():
			check_completed()
			return
		
		# get next action
		var action : Action = actions[next_action]
		next_action += 1
		
		# skip action is not enabled
		if !action.is_enabled:
			continue
		
		# bind completed signal and run
		action.connect("completed", self, "_on_completed", [action])
		action.start()
		
		# increment counts
		active_count += 1
		is_blocked = action.is_blocking


func check_completed():
	if active_count <= 0:
		emit_signal("completed")


func _on_completed(action : Action):
	# decrement counts
	active_count -= 1
	if action.is_blocking:
		is_blocked = false
	
	start_next()
