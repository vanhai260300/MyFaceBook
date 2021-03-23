<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->

<html>
    <head>
        <meta charset="UTF-8">
        <title>Task List Manager</title>
        <link href="style.css" rel="stylesheet" type="text/css"/>
        <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.1/css/bootstrap.min.css">
    </head>
    <body>
        <div class="page">
            <div class="head">
                <h1>Task List Manager</h1>
            </div>
            <div class="main">
                <h2>Task</h2>

                <?php if(count($task_list)==0): ?>
                    <P>There are no task in the Task List</p>
                <?php else : ?>
                    <ul>
                        <?php foreach ($task_list as $id => $task): ?>
                            <li><?php echo $id+1 .". ".$task; ?></li>
                        <?php endforeach; ?>
                    </ul>
                <?php endif; ?>
                <h2>Add List Manager</h2>
                <form method="POST" action=".">
                    <?php 
                    foreach($task_list as $task):?>
                    <input type="hidden" name="tasklist[]" value="<?php echo $task; ?>"/>
                    <?php
                    endforeach;
                    ?>
                    <input type="hidden" name="action" value="add"/>
                    <label> Task:</label> <input type="text" name="newTask" id="newTask"/> <br/><br/>
                    <label>&nbsp</label><input type="submit" value="Add Task"/>
                </form>
                <h2>Delete List Manager</h2>
                <form method="POST" action=".">
                    <?php 
                    foreach($task_list as $task):?>
                    <input type="hidden" name="tasklist[]" value="<?php echo $task; ?>"/>
                    <?php
                    endforeach;
                    ?>
                    <input type="hidden" name="action" value="delete"/>
                    <label> Task:</label>
                    <select name="taskid">
                        <?php foreach ($task_list as $id => $task): ?>
                        <option value="<?php echo $id;?>">
                            <?php echo $task;?>
                            
                        </option>
                        <?php endforeach;?>
                    </select>
                    <label>&nbsp</label><input type="submit" value="Delete Task"/>
                </form>
            </div>     
        </div> 
        <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.1.1/js/bootstrap.min.js"></script>
    </body>
</html>
