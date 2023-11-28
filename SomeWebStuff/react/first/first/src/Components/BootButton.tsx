import Alert from "./Alert";

interface Props{
    type?: string;
    children: React.ReactNode;
    onClick: () => void;
}



const BootButton = ( {type = "primary", children, onClick} : Props ) => {
    return <><button className={`btn btn-${type}`} onClick={() => onClick()}>{children}</button></>
}

export default BootButton;