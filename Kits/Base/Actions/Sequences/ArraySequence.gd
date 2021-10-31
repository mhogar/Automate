extends Sequence
class_name ArraySequence

export var delay : float = 1.0
export(NodePath) var actors_path

onready var delay_scene = preload("res://Kits/Base/Actions/Delay.tscn")
onready var actors : Array = get_node(actors_path).get_children()
onready var action : Action = get_child(0)


func _ready():
	for i in actors.size()-1:
		add_delay_action()
		add_action(action.duplicate(), actors[i+1])
	
	action.actor = actors[0]


func add_action(action : Action, actor: Actor):
	if actor != null:
		action.actor_path = actor.get_path()
		
	actions.append(action)
	add_child(action)


func add_delay_action():
	var action : DelayAction = delay_scene.instance()
	action.duration = delay
	add_action(action, null)
