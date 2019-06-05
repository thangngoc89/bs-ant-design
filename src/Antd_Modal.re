[@bs.module "antd/lib/modal"]
external reactClass: ReasonReact.reactClass = "default";

[%bs.raw {|require("antd/lib/modal/style")|}];

[@bs.obj]
external makeProps:
  (
    ~visible: bool=?,
    ~confirmLoading: bool=?,
    ~title: ReasonReact.reactElement=?,
    ~closable: bool=?,
    ~onOk: ReactEvent.Mouse.t => unit=?,
    ~onCancel: ReactEvent.Mouse.t => unit=?,
    ~afterClose: unit => unit=?,
    ~centered: bool=?,
    ~width: int=?,
    ~footer: ReasonReact.reactElement=?,
    ~okText: string=?,
    ~okType: Antd_Button.buttonType=?,
    ~cancelText: string=?,
    ~maskClosable: bool=?,
    /* okButtonProps?: NativeButtonProps;
       cancelButtonProps?: NativeButtonProps; */
    ~destroyOnClose: bool=?,
    ~style: ReactDOMRe.Style.t=?,
    ~wrapClassName: string=?,
    ~maskTransitionName: string=?,
    ~transitionName: string=?,
    ~className: string=?,
    /* getContainer?: (instance: React.ReactInstance) => HTMLElement; */
    ~zIndex: int=?,
    ~bodyStyle: ReactDOMRe.Style.t=?,
    ~maskStyle: ReactDOMRe.Style.t=?,
    ~mask: bool=?,
    ~keyboard: bool=?,
    ~wrapProps: unit=?,
    ~prefixCls: string=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~visible=?,
      ~confirmLoading=?,
      ~title=?,
      ~closable=?,
      ~onOk=?,
      ~onCancel=?,
      ~afterClose=?,
      ~centered=?,
      ~width=?,
      ~footer=?,
      ~okText=?,
      ~okType=?,
      ~cancelText=?,
      ~maskClosable=?,
      ~destroyOnClose=?,
      ~style=?,
      ~wrapClassName=?,
      ~maskTransitionName=?,
      ~transitionName=?,
      ~className=?,
      ~zIndex=?,
      ~bodyStyle=?,
      ~maskStyle=?,
      ~mask=?,
      ~keyboard=?,
      ~wrapProps=?,
      ~prefixCls=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~visible?,
        ~confirmLoading?,
        ~title?,
        ~closable?,
        ~onOk?,
        ~onCancel?,
        ~afterClose?,
        ~centered?,
        ~width?,
        ~footer?,
        ~okText?,
        ~okType?,
        ~cancelText?,
        ~maskClosable?,
        ~destroyOnClose?,
        ~style?,
        ~wrapClassName?,
        ~maskTransitionName?,
        ~transitionName?,
        ~className?,
        ~zIndex?,
        ~bodyStyle?,
        ~maskStyle?,
        ~mask?,
        ~keyboard?,
        ~wrapProps?,
        ~prefixCls?,
        (),
      ),
    children,
  );