<?php
if (isset($_POST['tasklist'])) {
    $task_list = $_POST['tasklist'];
} else {
    $task_list = array();
}
$error = array();

if (empty($_POST['action'])) {
    include 'task_list.php';
    return;
} else {
    /* @var $_POST type */
    switch ($_POST['action']) {
        case "add":
            $newTask = $_POST['newTask'];
            if (empty($newTask)) {
                $error[] = 'The new Task cannot be empty';
            } else {
                $task_list[] = $newTask;
            }
            break;
        case "delete":
            $task_index = $_POST['taskid'];
            unset($task_list[$task_index]);
            $task_list = array_values($task_list);
            break;
    }
}
include 'task_list.php';
?>


